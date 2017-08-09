
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* State Simulator Display Entity */

void adm_sim_display_entity_state(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_state_typ * ent_state;

    adm_sim_width_state_typ width_state;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_state");
    #endif

    width_state.identity = strlen("Identity");
    width_state.status = strlen("Status");

    ent_state = adm_entity_system.ent_state.live_list_head;

    while (ent_state != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_state->identity);
        if (width > width_state.identity) width_state.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_state[ent_state->status]);
        if (width > width_state.status) width_state.status = width;

        ent_state = ent_state->next;
    }

    printf(NEWLINE);
    printf("State:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_state.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_state.status, "Status");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_state.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_state.status);

    ent_state = adm_entity_system.ent_state.live_list_head;

    while (ent_state != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_state.identity, ent_state->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_state->status) {
            case ADM_STATUS_STATE_PROCESS_STATE :
                printf("%-*s", width_state.status, "Process_State");
            break;
            default :
                printf("%-*s", width_state.status, "ERROR");
            break;
        }


        ent_state = ent_state->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_state");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */