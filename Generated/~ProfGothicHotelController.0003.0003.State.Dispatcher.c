
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* State Dispatcher */

/* Dispatcher */

void adm_dispatcher_state(
    void)
{
    adm_pool_target_state_typ * pool_target_state;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_state");
    #endif

    pool_target_state = adm_find_away_target_event_state();

    adm_dispatch_state_action_state(pool_target_state);

    adm_dispatch_home_pool_state();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_state");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_state(
    void)
{
    adm_pool_target_state_typ * pool_target_state;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_state");
    #endif

    while (adm_entity_system.ent_state.home_pool_head != NULL) {

        pool_target_state = adm_find_home_target_event_state();

        adm_dispatch_state_action_state(pool_target_state);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_state");
    #endif
}


/* Find Home Target Event */

adm_pool_target_state_typ * adm_find_home_target_event_state(
    void)
{
    adm_pool_target_state_typ * pool_target_state;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_state");
    #endif

    pool_target_state = adm_entity_system.ent_state.home_pool_head;

    adm_entity_system.ent_state.home_pool_head = pool_target_state->next;

    if (adm_entity_system.ent_state.home_pool_head == NULL) {

        adm_entity_system.ent_state.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_state");
    #endif

    return (pool_target_state);
}


/* Find Away Target Event */

adm_pool_target_state_typ * adm_find_away_target_event_state(
    void)
{
    adm_pool_target_state_typ * pool_target_state;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_state");
    #endif

    pool_target_state = adm_entity_system.ent_state.away_pool_head;

    adm_entity_system.ent_state.away_pool_head = pool_target_state->next;

    if (adm_entity_system.ent_state.away_pool_head == NULL) {

        adm_entity_system.ent_state.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_state");
    #endif

    return (pool_target_state);
}


/* Dispatch State Action */

void adm_dispatch_state_action_state(
    adm_pool_target_state_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_state");
    #endif

    if (pool_target->ent_state != NULL) {

        adm_object_existent_state(
            pool_target->ent_state,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_STATE_ACTION_TRANSITION :

            switch ((pool_target->ent_state)->status) {

                case ADM_STATUS_STATE_PROCESS_STATE :

                    adm_sim_display_state_state_process_state(pool_target);

                    (pool_target->ent_state)->status = ADM_STATUS_STATE_PROCESS_STATE;

                    adm_state_action_state_process_state(
                        pool_target->ent_state);

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_state");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */