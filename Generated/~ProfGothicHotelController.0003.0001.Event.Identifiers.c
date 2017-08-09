
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Check Event Identifiers Unique */

void adm_check_identifiers_unique_event(
    adm_ent_event_typ * ent_source_event,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_ent_event_typ * ent_target_event;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_event");
    #endif

    ent_target_event = adm_entity_system.ent_event.live_list_head;

    while (ent_target_event != NULL) {

        if (
            !strcmp(
                ent_target_event->atb_code, ent_source_event->atb_code)) {

            adm_error_report(
                ADM_ERROR_OBJECT_IDENTIFIER_ATTRIBUTES_NOT_UNIQUE,
                error_file, error_line, error_rank,
                "Event",
                ent_target_event->identity,
                NULL,
                NULL);
        }

        ent_target_event = ent_target_event->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_event");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */