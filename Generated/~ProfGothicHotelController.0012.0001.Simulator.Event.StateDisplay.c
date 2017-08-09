
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Simulator Event Display State */

void adm_sim_display_state_event_idle(
    adm_pool_target_event_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_event_idle");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (2:18:26) - Event[");
        printf("%d", (pool_target->ent_event)->identity);
        printf("] ");
        printf("Idle");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_CONTROLLER_EVENT, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_event[(pool_target->ent_event)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_event_idle");
    #endif
}

void adm_sim_display_state_event_initialising(
    adm_pool_target_event_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_event_initialising");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (2:37:26) - Event[");
        printf("%d", (pool_target->ent_event)->identity);
        printf("] ");
        printf("Initialising");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_CONTROLLER_EVENT, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_event[(pool_target->ent_event)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_event_initialising");
    #endif
}

void adm_sim_display_state_event_process_event(
    adm_pool_target_event_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_event_process_event");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (2:52:26) - Event[");
        printf("%d", (pool_target->ent_event)->identity);
        printf("] ");
        printf("Process_Event");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_CONTROLLER_EVENT, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_event[(pool_target->ent_event)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_event_process_event");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */