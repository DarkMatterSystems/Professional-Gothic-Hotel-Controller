
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Command Data Access */

/* Make Entity Object */

adm_ent_command_typ * adm_make_object_command(
    adm_sta_command_typ status)
{
    adm_ent_command_typ * ent_command;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_command");
    #endif

    if (adm_entity_system.ent_command.dead_list_head != NULL) {

        ent_command = adm_entity_system.ent_command.dead_list_head;

        if (adm_entity_system.ent_command.dead_list_head == ent_command) {

            adm_entity_system.ent_command.dead_list_head = ent_command->next;

        } else {

            (ent_command->back)->next = ent_command->next;
        }

        if (adm_entity_system.ent_command.dead_list_tail == ent_command) {

            adm_entity_system.ent_command.dead_list_tail = ent_command->back;

        } else {

            (ent_command->next)->back = ent_command->back;
        }

    } else {

        ent_command = (adm_ent_command_typ*)adm_allocate_memory(sizeof(adm_ent_command_typ));
    }

    ent_command->identity = ++adm_entity_system.ent_command.tote;

    ent_command->unique  = FALSE;
    ent_command->deleted = FALSE;
    ent_command->marked  = FALSE;
    ent_command->status  = status;

    ent_command->atb_code = (adm_str_code_name_typ*)adm_allocate_memory(ADM_TYPE_SIZE_CODE_NAME+1);

    ent_command->back = NULL;
    ent_command->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_command");
    #endif

    return (ent_command);
}


/* Bind Entity Object */

void adm_bind_object_command(
    adm_ent_command_typ * ent_command,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_command");
    #endif

    adm_object_existent_command(
        ent_command,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_command.live_list_head == NULL) {

        ent_command->back = NULL;

        adm_entity_system.ent_command.live_list_head = ent_command;

    } else {

        ent_command->back = adm_entity_system.ent_command.live_list_tail;

        (adm_entity_system.ent_command.live_list_tail)->next = ent_command;
    }

    ent_command->next = NULL;

    adm_entity_system.ent_command.live_list_tail = ent_command;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_command");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_command(
    void * source_object,
    adm_ent_command_typ * ent_command,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_command");
    #endif

    adm_object_existent_command(
        ent_command,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_command) {

        if (adm_entity_system.ent_command.live_list_head == ent_command) {

            adm_entity_system.ent_command.live_list_head = ent_command->next;

        } else {

            (ent_command->back)->next = ent_command->next;
        }

        if (adm_entity_system.ent_command.live_list_tail == ent_command) {

            adm_entity_system.ent_command.live_list_tail = ent_command->back;

        } else {

            (ent_command->next)->back = ent_command->back;
        }

        adm_deallocate_memory(ent_command->atb_code);

        ent_command->deleted = TRUE;

        if (adm_entity_system.ent_command.dead_list_head == NULL) {

            ent_command->back = NULL;

            adm_entity_system.ent_command.dead_list_head = ent_command;

        } else {

            ent_command->back = adm_entity_system.ent_command.dead_list_tail;

            (adm_entity_system.ent_command.dead_list_tail)->next = ent_command;
        }

        ent_command->next = NULL;

        adm_entity_system.ent_command.dead_list_tail = ent_command;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Command",
            ent_command->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_command");
    #endif
}


/* Object Existent */

void adm_object_existent_command(
    const adm_ent_command_typ * const ent_command,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_command");
    #endif

    if (ent_command->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Command",
            ent_command->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_command");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */