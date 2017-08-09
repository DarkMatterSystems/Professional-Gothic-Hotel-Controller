
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Transition State Actions */

void adm_state_action_transition_process_transition(
    adm_ent_transition_typ * const ent_transition)
{
    /* Entity Objects */
    adm_ent_event_typ * ent_event_0000000001;
    adm_ent_state_typ * ent_state_0000000002;
    adm_ent_state_machine_typ * ent_state_machine_0000000002;
    adm_ent_state_typ * ent_state_0000000003;

    /* Relationship Relations */
    adm_rel_transition_determines_current_event_typ * rel_transition_determines_current_event_0000000001;
    adm_rel_transition_consumed_by_state_typ * rel_transition_consumed_by_state_0000000002;
    adm_rel_state_marks_current_state_for_state_machine_typ * rel_state_marks_current_state_for_state_machine_0000000002;
    adm_rel_transition_moves_to_next_state_typ * rel_transition_moves_to_next_state_0000000003;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000004;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_transition_process_transition");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_transition(
        ent_transition,
        3, 22, 29);

    rel_transition_determines_current_event_0000000001 = ent_transition->rel_determines_current_event_head;

    if (rel_transition_determines_current_event_0000000001 != NULL) {

        ent_event_0000000001 = rel_transition_determines_current_event_0000000001->ent_event;

        /* Traverse - TraverseSelection */

        adm_object_existent_transition(
            ent_transition,
            3, 26, 37);

        traverse_not_found_0000000004 = TRUE;

        rel_transition_consumed_by_state_0000000002 = ent_transition->rel_consumed_by_state_head;

        while (rel_transition_consumed_by_state_0000000002 != NULL) {

            ent_state_0000000002 = rel_transition_consumed_by_state_0000000002->ent_state;

            rel_state_marks_current_state_for_state_machine_0000000002 = ent_state_0000000002->rel_marks_current_state_for_state_machine_head;

            if (rel_state_marks_current_state_for_state_machine_0000000002 != NULL) {

                ent_state_machine_0000000002 = rel_state_marks_current_state_for_state_machine_0000000002->ent_state_machine;

                traverse_not_found_0000000004 = FALSE;

                /* Traverse - TraverseSelection */

                adm_object_existent_transition(
                    ent_transition,
                    3, 32, 45);

                rel_transition_moves_to_next_state_0000000003 = ent_transition->rel_moves_to_next_state_head;

                if (rel_transition_moves_to_next_state_0000000003 != NULL) {

                    ent_state_0000000003 = rel_transition_moves_to_next_state_0000000003->ent_state;

                    /* Unrelate */

                    adm_kill_relation_state_marks_current_state_for_state_machine(
                        ent_state_0000000002,
                        rel_state_marks_current_state_for_state_machine_0000000002,
                        3, 36, 49);

                    /* Relate */

                    adm_link_relation_state_marks_current_state_for_state_machine(
                        ent_state_0000000003,
                        ent_state_machine_0000000002,
                        3, 38, 49);

                    /* GenerateEvent */

                    adm_send_event_state_action_transition(
                        ent_transition,
                        ent_state_0000000003,
                        3, 40, 49);

                } else {

                    adm_error_report(
                        ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                        3, 32, 45,
                        "Transition",
                        ent_transition->identity,
                        "Moves_to_next",
                        "State");
                }

                /* GenerateEvent */

                adm_send_event_event_state_processed(
                    ent_transition,
                    ent_event_0000000001,
                    3, 42, 41);
            }

            rel_transition_consumed_by_state_0000000002 = rel_transition_consumed_by_state_0000000002->next;
        }

        /* Traverse - Null Traverse Selection */

        if (traverse_not_found_0000000004) {

            /* Assignment - Set */

            ent_transition->atb_processed = TRUE;

            /* GenerateEvent */

            adm_send_event_event_state_not_found(
                ent_transition,
                ent_event_0000000001,
                3, 48, 41);
        }

        /* Unrelate */

        adm_kill_relation_transition_determines_current_event(
            ent_transition,
            rel_transition_determines_current_event_0000000001,
            3, 50, 33);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_transition_process_transition");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */