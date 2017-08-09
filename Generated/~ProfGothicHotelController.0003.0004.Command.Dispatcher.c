
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Command Dispatcher */

/* Dispatcher */

void adm_dispatcher_command(
    void)
{
    adm_pool_target_command_typ * pool_target_command;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_command");
    #endif

    pool_target_command = adm_find_away_target_event_command();

    adm_dispatch_state_action_command(pool_target_command);

    adm_dispatch_home_pool_command();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_command");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_command(
    void)
{
    adm_pool_target_command_typ * pool_target_command;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_command");
    #endif

    while (adm_entity_system.ent_command.home_pool_head != NULL) {

        pool_target_command = adm_find_home_target_event_command();

        adm_dispatch_state_action_command(pool_target_command);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_command");
    #endif
}


/* Find Home Target Event */

adm_pool_target_command_typ * adm_find_home_target_event_command(
    void)
{
    adm_pool_target_command_typ * pool_target_command;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_command");
    #endif

    pool_target_command = adm_entity_system.ent_command.home_pool_head;

    adm_entity_system.ent_command.home_pool_head = pool_target_command->next;

    if (adm_entity_system.ent_command.home_pool_head == NULL) {

        adm_entity_system.ent_command.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_command");
    #endif

    return (pool_target_command);
}


/* Find Away Target Event */

adm_pool_target_command_typ * adm_find_away_target_event_command(
    void)
{
    adm_pool_target_command_typ * pool_target_command;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_command");
    #endif

    pool_target_command = adm_entity_system.ent_command.away_pool_head;

    adm_entity_system.ent_command.away_pool_head = pool_target_command->next;

    if (adm_entity_system.ent_command.away_pool_head == NULL) {

        adm_entity_system.ent_command.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_command");
    #endif

    return (pool_target_command);
}


/* Dispatch State Action */

void adm_dispatch_state_action_command(
    adm_pool_target_command_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_command");
    #endif

    if (pool_target->ent_command != NULL) {

        adm_object_existent_command(
            pool_target->ent_command,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_COMMAND_ACTION_STATE :

            switch ((pool_target->ent_command)->status) {

                case ADM_STATUS_COMMAND_PROCESS_COMMAND :

                    adm_sim_display_state_command_process_command(pool_target);

                    (pool_target->ent_command)->status = ADM_STATUS_COMMAND_PROCESS_COMMAND;

                    adm_state_action_command_process_command(
                        pool_target->ent_command);

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_command");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */