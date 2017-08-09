
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* State Machine Data Access */

/* Make Entity Object */

adm_ent_state_machine_typ * adm_make_object_state_machine(
    void)
{
    adm_ent_state_machine_typ * ent_state_machine;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_state_machine");
    #endif

    if (adm_entity_system.ent_state_machine.dead_list_head != NULL) {

        ent_state_machine = adm_entity_system.ent_state_machine.dead_list_head;

        if (adm_entity_system.ent_state_machine.dead_list_head == ent_state_machine) {

            adm_entity_system.ent_state_machine.dead_list_head = ent_state_machine->next;

        } else {

            (ent_state_machine->back)->next = ent_state_machine->next;
        }

        if (adm_entity_system.ent_state_machine.dead_list_tail == ent_state_machine) {

            adm_entity_system.ent_state_machine.dead_list_tail = ent_state_machine->back;

        } else {

            (ent_state_machine->next)->back = ent_state_machine->back;
        }

    } else {

        ent_state_machine = (adm_ent_state_machine_typ*)adm_allocate_memory(sizeof(adm_ent_state_machine_typ));
    }

    ent_state_machine->identity = ++adm_entity_system.ent_state_machine.tote;

    ent_state_machine->unique  = FALSE;
    ent_state_machine->deleted = FALSE;
    ent_state_machine->marked  = FALSE;
    ent_state_machine->ignore  = null;

    ent_state_machine->back = NULL;
    ent_state_machine->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_state_machine");
    #endif

    return (ent_state_machine);
}


/* Bind Entity Object */

void adm_bind_object_state_machine(
    adm_ent_state_machine_typ * ent_state_machine,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_state_machine");
    #endif

    adm_object_existent_state_machine(
        ent_state_machine,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_state_machine.live_list_head == NULL) {

        ent_state_machine->back = NULL;

        adm_entity_system.ent_state_machine.live_list_head = ent_state_machine;

    } else {

        ent_state_machine->back = adm_entity_system.ent_state_machine.live_list_tail;

        (adm_entity_system.ent_state_machine.live_list_tail)->next = ent_state_machine;
    }

    ent_state_machine->next = NULL;

    adm_entity_system.ent_state_machine.live_list_tail = ent_state_machine;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_state_machine");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_state_machine(
    void * source_object,
    adm_ent_state_machine_typ * ent_state_machine,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_state_machine");
    #endif

    adm_object_existent_state_machine(
        ent_state_machine,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_state_machine) {

        if (adm_entity_system.ent_state_machine.live_list_head == ent_state_machine) {

            adm_entity_system.ent_state_machine.live_list_head = ent_state_machine->next;

        } else {

            (ent_state_machine->back)->next = ent_state_machine->next;
        }

        if (adm_entity_system.ent_state_machine.live_list_tail == ent_state_machine) {

            adm_entity_system.ent_state_machine.live_list_tail = ent_state_machine->back;

        } else {

            (ent_state_machine->next)->back = ent_state_machine->back;
        }

        ent_state_machine->deleted = TRUE;

        if (adm_entity_system.ent_state_machine.dead_list_head == NULL) {

            ent_state_machine->back = NULL;

            adm_entity_system.ent_state_machine.dead_list_head = ent_state_machine;

        } else {

            ent_state_machine->back = adm_entity_system.ent_state_machine.dead_list_tail;

            (adm_entity_system.ent_state_machine.dead_list_tail)->next = ent_state_machine;
        }

        ent_state_machine->next = NULL;

        adm_entity_system.ent_state_machine.dead_list_tail = ent_state_machine;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "State_Machine",
            ent_state_machine->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_state_machine");
    #endif
}


/* Object Existent */

void adm_object_existent_state_machine(
    const adm_ent_state_machine_typ * const ent_state_machine,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_state_machine");
    #endif

    if (ent_state_machine->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "State_Machine",
            ent_state_machine->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_state_machine");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */