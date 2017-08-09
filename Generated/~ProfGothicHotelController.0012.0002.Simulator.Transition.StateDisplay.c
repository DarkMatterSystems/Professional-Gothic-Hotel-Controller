
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Simulator Transition Display State */

void adm_sim_display_state_transition_process_transition(
    adm_pool_target_transition_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_transition_process_transition");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (3:17:26) - Transition[");
        printf("%d", (pool_target->ent_transition)->identity);
        printf("] ");
        printf("Process_Transition");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_CONTROLLER_TRANSITION, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_transition[(pool_target->ent_transition)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_transition_process_transition");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */