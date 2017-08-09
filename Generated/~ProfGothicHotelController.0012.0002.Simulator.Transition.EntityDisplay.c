
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Transition Simulator Display Entity */

void adm_sim_display_entity_transition(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_transition_typ * ent_transition;

    adm_sim_width_transition_typ width_transition;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_transition");
    #endif

    width_transition.identity = strlen("Identity");
    width_transition.status = strlen("Status");
    width_transition.atb_processed = strlen("Processed");

    ent_transition = adm_entity_system.ent_transition.live_list_head;

    while (ent_transition != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_transition->identity);
        if (width > width_transition.identity) width_transition.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_transition[ent_transition->status]);
        if (width > width_transition.status) width_transition.status = width;

        if (ent_transition->atb_processed == TRUE || ent_transition->atb_processed == FALSE) {
            width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_boolean[ent_transition->atb_processed]);
            if (width > width_transition.atb_processed) width_transition.atb_processed = width;}

        ent_transition = ent_transition->next;
    }

    printf(NEWLINE);
    printf("Transition:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_transition.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_transition.status, "Status");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_transition.atb_processed, "Processed");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_transition.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_transition.status);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_transition.atb_processed);

    ent_transition = adm_entity_system.ent_transition.live_list_head;

    while (ent_transition != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_transition.identity, ent_transition->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_transition->status) {
            case ADM_STATUS_TRANSITION_PROCESS_TRANSITION :
                printf("%-*s", width_transition.status, "Process_Transition");
            break;
            default :
                printf("%-*s", width_transition.status, "ERROR");
            break;
        }

        printf(ADM_SIM_COLUMN_GAP);
        if (ent_transition->atb_processed == TRUE || ent_transition->atb_processed == FALSE)
            printf("%-*s", width_transition.atb_processed, adm_boolean[ent_transition->atb_processed]);
        else
            adm_sim_display_row('*', width_transition.atb_processed);

        ent_transition = ent_transition->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_transition");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */