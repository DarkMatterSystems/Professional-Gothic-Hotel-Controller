
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Simulator State Display State */

void adm_sim_display_state_state_process_state(
    adm_pool_target_state_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_state_process_state");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (4:14:26) - State[");
        printf("%d", (pool_target->ent_state)->identity);
        printf("] ");
        printf("Process_State");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_CONTROLLER_STATE, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_state[(pool_target->ent_state)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_state_process_state");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */