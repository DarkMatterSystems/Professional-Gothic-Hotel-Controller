
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* State Event Senders */

void adm_send_event_state_action_transition(
    const void * const source_object,
    const adm_ent_state_typ * const ent_state,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_state_typ * pool_target;
    adm_pool_target_state_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_state_action_transition");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_state_action_transition(
            ent_state,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_state(
            ent_state,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_state_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_state_typ));

        pool_target->evente = ADM_EVENT_STATE_ACTION_TRANSITION;
        pool_target->ent_state = (adm_ent_state_typ*)ent_state;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_state) {

            if (adm_entity_system.ent_state.home_pool_head == NULL) {

                adm_entity_system.ent_state.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_state.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_state == ent_state) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "State",
                            ent_state->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_state.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_state.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_state.away_pool_head == NULL) {

                adm_entity_system.ent_state.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_state.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_state.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_state_action_transition");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */