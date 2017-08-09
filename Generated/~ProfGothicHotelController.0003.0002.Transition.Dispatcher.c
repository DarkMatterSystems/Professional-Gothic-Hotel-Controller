
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Transition Dispatcher */

/* Dispatcher */

void adm_dispatcher_transition(
    void)
{
    adm_pool_target_transition_typ * pool_target_transition;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_transition");
    #endif

    pool_target_transition = adm_find_away_target_event_transition();

    adm_dispatch_state_action_transition(pool_target_transition);

    adm_dispatch_home_pool_transition();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_transition");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_transition(
    void)
{
    adm_pool_target_transition_typ * pool_target_transition;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_transition");
    #endif

    while (adm_entity_system.ent_transition.home_pool_head != NULL) {

        pool_target_transition = adm_find_home_target_event_transition();

        adm_dispatch_state_action_transition(pool_target_transition);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_transition");
    #endif
}


/* Find Home Target Event */

adm_pool_target_transition_typ * adm_find_home_target_event_transition(
    void)
{
    adm_pool_target_transition_typ * pool_target_transition;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_transition");
    #endif

    pool_target_transition = adm_entity_system.ent_transition.home_pool_head;

    adm_entity_system.ent_transition.home_pool_head = pool_target_transition->next;

    if (adm_entity_system.ent_transition.home_pool_head == NULL) {

        adm_entity_system.ent_transition.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_transition");
    #endif

    return (pool_target_transition);
}


/* Find Away Target Event */

adm_pool_target_transition_typ * adm_find_away_target_event_transition(
    void)
{
    adm_pool_target_transition_typ * pool_target_transition;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_transition");
    #endif

    pool_target_transition = adm_entity_system.ent_transition.away_pool_head;

    adm_entity_system.ent_transition.away_pool_head = pool_target_transition->next;

    if (adm_entity_system.ent_transition.away_pool_head == NULL) {

        adm_entity_system.ent_transition.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_transition");
    #endif

    return (pool_target_transition);
}


/* Dispatch State Action */

void adm_dispatch_state_action_transition(
    adm_pool_target_transition_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_transition");
    #endif

    if (pool_target->ent_transition != NULL) {

        adm_object_existent_transition(
            pool_target->ent_transition,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_TRANSITION_ACTION_EVENT :

            switch ((pool_target->ent_transition)->status) {

                case ADM_STATUS_TRANSITION_PROCESS_TRANSITION :

                    adm_sim_display_state_transition_process_transition(pool_target);

                    (pool_target->ent_transition)->status = ADM_STATUS_TRANSITION_PROCESS_TRANSITION;

                    adm_state_action_transition_process_transition(
                        pool_target->ent_transition);

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_transition");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */