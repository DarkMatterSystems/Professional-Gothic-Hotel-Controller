
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Simulator Command Display State */

void adm_sim_display_state_command_process_command(
    adm_pool_target_command_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_command_process_command");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (5:13:26) - Command[");
        printf("%d", (pool_target->ent_command)->identity);
        printf("] ");
        printf("Process_Command");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_CONTROLLER_COMMAND, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_command[(pool_target->ent_command)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_command_process_command");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */