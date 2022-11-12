/*
 * Evaluator.cpp
 *
 *  Created on: 5 Oct 2017
 *      Author: panpan
 */

#include <despot/planner.h>
#include <iostream>

namespace despot {
    ofstream myfile;

    void Planner::EvaluationLoop(DSPOMDP *model, World* world, Belief* belief,
                                 string belief_type, Solver *&solver, Logger *logger,
                                 option::Option *options, clock_t main_clock_start, int num_runs,
                                 int start_run) {
        // Run num_runs simulations
        vector<double> round_rewards(num_runs);
        for (int round = start_run; round < start_run + num_runs; round++) {
            round_=round;
            step_=0;
            default_out<< endl
                       << "####################################### Round " << round
                       << " #######################################" << endl;
            //Reset world and logger
            world->Initialize();
            logger->InitRound(world->GetCurrentState());

            //Reset belief and solver
            double start_t = get_time_second();
            delete solver->belief();
            double end_t = get_time_second();
            logi << "[Initializer::EvaluationLoop] Deleted old belief in "
                 << (end_t - start_t) << "s" << endl;

            start_t = get_time_second();
            belief=model->InitialBelief(world->GetCurrentState(), belief_type);
            end_t = get_time_second();
            logi << "[Initializer::EvaluationLoop] Created intial belief "
                 << typeid(*belief).name() << " in " << (end_t - start_t) << "s" << endl;

            solver->belief(belief);
            logger->belief(belief);

            //start loop
            PlanningLoop(solver, world, logger);
            //end loop

            default_out << "Simulation terminated in " << logger->step() << " steps"
                        << endl;
            double round_reward = logger->EndRound();

            myfile << logger->total_discounted_reward_round() << "/"<<round_reward <<"\n";
            round_rewards[round] = round_reward;
        }
    }

    int Planner::RunEvaluation(int argc, char *argv[]) {

        /* =========================
         * initialize parameters
         * =========================*/
        string solver_type = ChooseSolver();
        bool search_solver;
        int num_runs = 20;
        string world_type = "pomdp";
        string belief_type = "DEFAULT";
        int time_limit = -1;

        option::Option *options = InitializeParamers(argc, argv, solver_type,
                                                     search_solver, num_runs, world_type, belief_type, time_limit);
        if(options==NULL)
            return 0;
        clock_t main_clock_start = clock();

        /* =========================
         * initialize model
         * =========================*/
        DSPOMDP *model = InitializeModel(options);
        assert(model != NULL);

        /* =========================
         * initialize world
         * =========================*/
        World *world = InitializeWorld(world_type, model, options);
        assert(world != NULL);

        /* =========================
         * initialize belief
         * =========================*/
        Belief* belief = model->InitialBelief(world->GetCurrentState(), belief_type);
        assert(belief != NULL);

        /* =========================
         * initialize solver
         * =========================*/
        //TB file
        ofstream rollout_file;
        string rollout_file_name = solver_type+"_"+typeid(*model).name()+"_rollouts_uniform_action_test.csv";
        rollout_file.open (rollout_file_name);
        //TB file

        Solver *solver = InitializeSolver(model, belief, solver_type, options, &rollout_file);

        /* =========================
         * initialize logger
         * =========================*/
        Logger *logger = NULL;
        InitializeLogger(logger, options, model, belief, solver, num_runs,
                         main_clock_start, world, world_type, time_limit, solver_type);
        //logger->world_seed(world_seed);

        int start_run = 0;

        /* =========================
         * Display parameters
         * =========================*/
        DisplayParameters(options, model);

        /* =========================
         * run evaluation
         * =========================*/

//        string file_name = solver_type+"_"+typeid(*model).name()+"_20sim_heuristic_rollout_ghostsNear.txt";
//        string file_name = solver_type+"_"+typeid(*model).name()+"_90sim_heuristic_rollout_ghostsNear_foodPallet_test.txt";
        string file_name = solver_type+"_"+typeid(*model).name()+"_test.txt";
//        string file_name = solver_type+"_"+typeid(*model).name()+"_90sim_Manhattan_heuristic_rewardTag_discount1_default_policy_tag.txt";
//        string file_name = solver_type+"_"+typeid(*model).name()+"_10sim_Manhattan_heuristic_rewardTag.txt";
//        string file_name = solver_type+"_"+typeid(*model).name()+"_90sim_discount1_default_policy.txt";
//        string file_name = solver_type+"_"+typeid(*model).name()+"_90sim_no_preferred_CreateVNode.txt";
        myfile.open (file_name);
        myfile << "round__discounted_reward/round_undiscounted_reward\n";


        EvaluationLoop(model, world, belief, belief_type, solver, logger,
                       options, main_clock_start, num_runs, start_run);

        //logger->End();

        myfile.close();
        rollout_file.close(); //TB file

        PrintResult(num_runs, logger, main_clock_start);

        return 0;
    }

} /* namespace despot */
