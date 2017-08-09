
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Event Dispatcher */

/* Dispatcher */

void adm_dispatcher_event(
    void)
{
    adm_pool_target_event_typ * pool_target_event;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_event");
    #endif

    pool_target_event = adm_find_away_target_event_event();

    adm_dispatch_state_action_event(pool_target_event);

    adm_dispatch_home_pool_event();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_event");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_event(
    void)
{
    adm_pool_target_event_typ * pool_target_event;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_event");
    #endif

    while (adm_entity_system.ent_event.home_pool_head != NULL) {

        pool_target_event = adm_find_home_target_event_event();

        adm_dispatch_state_action_event(pool_target_event);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_event");
    #endif
}


/* Find Home Target Event */

adm_pool_target_event_typ * adm_find_home_target_event_event(
    void)
{
    adm_pool_target_event_typ * pool_target_event;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_event");
    #endif

    pool_target_event = adm_entity_system.ent_event.home_pool_head;

    adm_entity_system.ent_event.home_pool_head = pool_target_event->next;

    if (adm_entity_system.ent_event.home_pool_head == NULL) {

        adm_entity_system.ent_event.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_event");
    #endif

    return (pool_target_event);
}


/* Find Away Target Event */

adm_pool_target_event_typ * adm_find_away_target_event_event(
    void)
{
    adm_pool_target_event_typ * pool_target_event;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_event");
    #endif

    pool_target_event = adm_entity_system.ent_event.away_pool_head;

    adm_entity_system.ent_event.away_pool_head = pool_target_event->next;

    if (adm_entity_system.ent_event.away_pool_head == NULL) {

        adm_entity_system.ent_event.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_event");
    #endif

    return (pool_target_event);
}


/* Dispatch State Action */

void adm_dispatch_state_action_event(
    adm_pool_target_event_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_event");
    #endif

    if (pool_target->ent_event != NULL) {

        adm_object_existent_event(
            pool_target->ent_event,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_EVENT_DEVICE_UPDATE :

            switch ((pool_target->ent_event)->status) {

                case ADM_STATUS_EVENT_IDLE :

                    adm_sim_display_state_event_initialising(pool_target);

                    (pool_target->ent_event)->status = ADM_STATUS_EVENT_INITIALISING;

                    adm_state_action_event_initialising(
                        pool_target->ent_event);

                break;
            }

        break;

        case ADM_EVENT_EVENT_STATE_PROCESSED :

            switch ((pool_target->ent_event)->status) {

                case ADM_STATUS_EVENT_IDLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Event",
                        (pool_target->ent_event)->identity,
                        "Event:State_processed",
                        "State:Idle");

                break;

                case ADM_STATUS_EVENT_INITIALISING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Event",
                        (pool_target->ent_event)->identity,
                        "Event:State_processed",
                        "State:Initialising");

                break;

                case ADM_STATUS_EVENT_PROCESS_EVENT :

                    adm_sim_display_state_event_idle(pool_target);

                    (pool_target->ent_event)->status = ADM_STATUS_EVENT_IDLE;

                    adm_state_action_event_idle(
                        pool_target->ent_event);

                break;
            }

        break;

        case ADM_EVENT_EVENT_STATE_NOT_FOUND :

            switch ((pool_target->ent_event)->status) {

                case ADM_STATUS_EVENT_IDLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Event",
                        (pool_target->ent_event)->identity,
                        "Event:State_not_found",
                        "State:Idle");

                break;

                case ADM_STATUS_EVENT_INITIALISING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Event",
                        (pool_target->ent_event)->identity,
                        "Event:State_not_found",
                        "State:Initialising");

                break;

                case ADM_STATUS_EVENT_PROCESS_EVENT :

                    adm_sim_display_state_event_process_event(pool_target);

                    (pool_target->ent_event)->status = ADM_STATUS_EVENT_PROCESS_EVENT;

                    adm_state_action_event_process_event(
                        pool_target->ent_event);

                break;
            }

        break;

        case ADM_EVENT_EVENT_DONE :

            switch ((pool_target->ent_event)->status) {

                case ADM_STATUS_EVENT_IDLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Event",
                        (pool_target->ent_event)->identity,
                        "Event:Done",
                        "State:Idle");

                break;

                case ADM_STATUS_EVENT_INITIALISING :

                    adm_sim_display_state_event_process_event(pool_target);

                    (pool_target->ent_event)->status = ADM_STATUS_EVENT_PROCESS_EVENT;

                    adm_state_action_event_process_event(
                        pool_target->ent_event);

                break;

                case ADM_STATUS_EVENT_PROCESS_EVENT :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Event",
                        (pool_target->ent_event)->identity,
                        "Event:Done",
                        "State:Process_Event");

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_event");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */