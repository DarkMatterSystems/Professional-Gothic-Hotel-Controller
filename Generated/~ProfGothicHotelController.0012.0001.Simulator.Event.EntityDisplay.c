
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Event Simulator Display Entity */

void adm_sim_display_entity_event(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_event_typ * ent_event;

    adm_sim_width_event_typ width_event;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_event");
    #endif

    width_event.identity = strlen("Identity");
    width_event.status = strlen("Status");
    width_event.atb_code = strlen("Code");

    ent_event = adm_entity_system.ent_event.live_list_head;

    while (ent_event != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_event->identity);
        if (width > width_event.identity) width_event.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_event[ent_event->status]);
        if (width > width_event.status) width_event.status = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_event->atb_code);
        if (width > width_event.atb_code) width_event.atb_code = width;

        ent_event = ent_event->next;
    }

    printf(NEWLINE);
    printf("Event:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_event.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_event.status, "Status");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_event.atb_code, "Code");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_event.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_event.status);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_event.atb_code);

    ent_event = adm_entity_system.ent_event.live_list_head;

    while (ent_event != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_event.identity, ent_event->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_event->status) {
            case ADM_STATUS_EVENT_IDLE :
                printf("%-*s", width_event.status, "Idle");
            break;
            case ADM_STATUS_EVENT_INITIALISING :
                printf("%-*s", width_event.status, "Initialising");
            break;
            case ADM_STATUS_EVENT_PROCESS_EVENT :
                printf("%-*s", width_event.status, "Process_Event");
            break;
            default :
                printf("%-*s", width_event.status, "ERROR");
            break;
        }

        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_event->atb_code);
        printf("%-*s", width_event.atb_code, buffer);

        ent_event = ent_event->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_event");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */