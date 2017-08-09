
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* State Data Access */

/* Make Entity Object */

adm_ent_state_typ * adm_make_object_state(
    adm_sta_state_typ status)
{
    adm_ent_state_typ * ent_state;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_state");
    #endif

    if (adm_entity_system.ent_state.dead_list_head != NULL) {

        ent_state = adm_entity_system.ent_state.dead_list_head;

        if (adm_entity_system.ent_state.dead_list_head == ent_state) {

            adm_entity_system.ent_state.dead_list_head = ent_state->next;

        } else {

            (ent_state->back)->next = ent_state->next;
        }

        if (adm_entity_system.ent_state.dead_list_tail == ent_state) {

            adm_entity_system.ent_state.dead_list_tail = ent_state->back;

        } else {

            (ent_state->next)->back = ent_state->back;
        }

    } else {

        ent_state = (adm_ent_state_typ*)adm_allocate_memory(sizeof(adm_ent_state_typ));
    }

    ent_state->identity = ++adm_entity_system.ent_state.tote;

    ent_state->unique  = FALSE;
    ent_state->deleted = FALSE;
    ent_state->marked  = FALSE;
    ent_state->status  = status;

    ent_state->rel_invokes_command_head = NULL;
    ent_state->rel_invokes_command_tail = NULL;

    ent_state->rel_marks_current_state_for_state_machine_head = NULL;
    ent_state->rel_marks_current_state_for_state_machine_tail = NULL;

    ent_state->back = NULL;
    ent_state->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_state");
    #endif

    return (ent_state);
}


/* Bind Entity Object */

void adm_bind_object_state(
    adm_ent_state_typ * ent_state,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_state");
    #endif

    adm_object_existent_state(
        ent_state,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_state.live_list_head == NULL) {

        ent_state->back = NULL;

        adm_entity_system.ent_state.live_list_head = ent_state;

    } else {

        ent_state->back = adm_entity_system.ent_state.live_list_tail;

        (adm_entity_system.ent_state.live_list_tail)->next = ent_state;
    }

    ent_state->next = NULL;

    adm_entity_system.ent_state.live_list_tail = ent_state;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_state");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_state(
    void * source_object,
    adm_ent_state_typ * ent_state,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_state");
    #endif

    adm_object_existent_state(
        ent_state,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_state) {

        if (ent_state->rel_invokes_command_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "State",
                ent_state->identity,
                "Invokes",
                "Command");
        }

        if (ent_state->rel_marks_current_state_for_state_machine_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "State",
                ent_state->identity,
                "Marks_current_state_for",
                "State_Machine");
        }

        if (adm_entity_system.ent_state.live_list_head == ent_state) {

            adm_entity_system.ent_state.live_list_head = ent_state->next;

        } else {

            (ent_state->back)->next = ent_state->next;
        }

        if (adm_entity_system.ent_state.live_list_tail == ent_state) {

            adm_entity_system.ent_state.live_list_tail = ent_state->back;

        } else {

            (ent_state->next)->back = ent_state->back;
        }

        ent_state->deleted = TRUE;

        if (adm_entity_system.ent_state.dead_list_head == NULL) {

            ent_state->back = NULL;

            adm_entity_system.ent_state.dead_list_head = ent_state;

        } else {

            ent_state->back = adm_entity_system.ent_state.dead_list_tail;

            (adm_entity_system.ent_state.dead_list_tail)->next = ent_state;
        }

        ent_state->next = NULL;

        adm_entity_system.ent_state.dead_list_tail = ent_state;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "State",
            ent_state->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_state");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_state_invokes_command(
    adm_ent_state_typ * ent_source_state,
    adm_ent_command_typ * ent_target_command,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_state_invokes_command_typ * rel_state_invokes_command;

    adm_base_boolean_typ command_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_state_invokes_command");
    #endif

    adm_object_existent_state(
        ent_source_state,
        error_file,
        error_line,
        error_rank);

    command_not_found = TRUE;

    rel_state_invokes_command = ent_source_state->rel_invokes_command_head;

    while (
        command_not_found &&
        rel_state_invokes_command != NULL) {

        if (rel_state_invokes_command->ent_command == ent_target_command) {

            command_not_found = FALSE;
        }

        rel_state_invokes_command = rel_state_invokes_command->next;
    }

    if (command_not_found) {

        rel_state_invokes_command = (adm_rel_state_invokes_command_typ*)
            adm_allocate_memory(sizeof(adm_rel_state_invokes_command_typ));

        rel_state_invokes_command->ent_command = ent_target_command;

        if (ent_source_state->rel_invokes_command_head == NULL) {

            rel_state_invokes_command->back = NULL;

            ent_source_state->rel_invokes_command_head = rel_state_invokes_command;

        } else {

            rel_state_invokes_command->back = ent_source_state->rel_invokes_command_tail;

            (ent_source_state->rel_invokes_command_tail)->next = rel_state_invokes_command;
        }

        rel_state_invokes_command->next = NULL;

        ent_source_state->rel_invokes_command_tail = rel_state_invokes_command;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "State",
            ent_source_state->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_state_invokes_command");
    #endif
}

void adm_link_relation_state_marks_current_state_for_state_machine(
    adm_ent_state_typ * ent_source_state,
    adm_ent_state_machine_typ * ent_target_state_machine,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_state_marks_current_state_for_state_machine_typ * rel_state_marks_current_state_for_state_machine;

    adm_base_boolean_typ state_machine_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_state_marks_current_state_for_state_machine");
    #endif

    adm_object_existent_state(
        ent_source_state,
        error_file,
        error_line,
        error_rank);

    state_machine_not_found = TRUE;

    rel_state_marks_current_state_for_state_machine = ent_source_state->rel_marks_current_state_for_state_machine_head;

    while (
        state_machine_not_found &&
        rel_state_marks_current_state_for_state_machine != NULL) {

        if (rel_state_marks_current_state_for_state_machine->ent_state_machine == ent_target_state_machine) {

            state_machine_not_found = FALSE;
        }

        rel_state_marks_current_state_for_state_machine = rel_state_marks_current_state_for_state_machine->next;
    }

    if (state_machine_not_found) {

        rel_state_marks_current_state_for_state_machine = (adm_rel_state_marks_current_state_for_state_machine_typ*)
            adm_allocate_memory(sizeof(adm_rel_state_marks_current_state_for_state_machine_typ));

        rel_state_marks_current_state_for_state_machine->ent_state_machine = ent_target_state_machine;

        if (ent_source_state->rel_marks_current_state_for_state_machine_head == NULL) {

            rel_state_marks_current_state_for_state_machine->back = NULL;

            ent_source_state->rel_marks_current_state_for_state_machine_head = rel_state_marks_current_state_for_state_machine;

        } else {

            rel_state_marks_current_state_for_state_machine->back = ent_source_state->rel_marks_current_state_for_state_machine_tail;

            (ent_source_state->rel_marks_current_state_for_state_machine_tail)->next = rel_state_marks_current_state_for_state_machine;
        }

        rel_state_marks_current_state_for_state_machine->next = NULL;

        ent_source_state->rel_marks_current_state_for_state_machine_tail = rel_state_marks_current_state_for_state_machine;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "State",
            ent_source_state->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_state_marks_current_state_for_state_machine");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_state_invokes_command(
    adm_ent_state_typ * ent_state,
    adm_rel_state_invokes_command_typ * rel_state_invokes_command,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_state_invokes_command");
    #endif

    adm_object_existent_state(
        ent_state,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_state_invokes_command->next !=
        (adm_base_integer_typ)rel_state_invokes_command->ent_command) {

        if (ent_state->rel_invokes_command_head != NULL) {

            if (ent_state->rel_invokes_command_head == rel_state_invokes_command) {

                ent_state->rel_invokes_command_head = rel_state_invokes_command->next;

            } else {

                (rel_state_invokes_command->back)->next = rel_state_invokes_command->next;
            }

            if (ent_state->rel_invokes_command_tail == rel_state_invokes_command) {

                ent_state->rel_invokes_command_tail = rel_state_invokes_command->back;

            } else {

                (rel_state_invokes_command->next)->back = rel_state_invokes_command->back;
            }

            adm_deallocate_memory(rel_state_invokes_command);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "State",
                ent_state->identity,
                "Invokes",
                "Command");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "State",
            ent_state->identity,
            "Invokes",
            "Command");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_state_invokes_command");
    #endif
}

void adm_kill_relation_state_marks_current_state_for_state_machine(
    adm_ent_state_typ * ent_state,
    adm_rel_state_marks_current_state_for_state_machine_typ * rel_state_marks_current_state_for_state_machine,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_state_marks_current_state_for_state_machine");
    #endif

    adm_object_existent_state(
        ent_state,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_state_marks_current_state_for_state_machine->next !=
        (adm_base_integer_typ)rel_state_marks_current_state_for_state_machine->ent_state_machine) {

        if (ent_state->rel_marks_current_state_for_state_machine_head != NULL) {

            if (ent_state->rel_marks_current_state_for_state_machine_head == rel_state_marks_current_state_for_state_machine) {

                ent_state->rel_marks_current_state_for_state_machine_head = rel_state_marks_current_state_for_state_machine->next;

            } else {

                (rel_state_marks_current_state_for_state_machine->back)->next = rel_state_marks_current_state_for_state_machine->next;
            }

            if (ent_state->rel_marks_current_state_for_state_machine_tail == rel_state_marks_current_state_for_state_machine) {

                ent_state->rel_marks_current_state_for_state_machine_tail = rel_state_marks_current_state_for_state_machine->back;

            } else {

                (rel_state_marks_current_state_for_state_machine->next)->back = rel_state_marks_current_state_for_state_machine->back;
            }

            adm_deallocate_memory(rel_state_marks_current_state_for_state_machine);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "State",
                ent_state->identity,
                "Marks_current_state_for",
                "State_Machine");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "State",
            ent_state->identity,
            "Marks_current_state_for",
            "State_Machine");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_state_marks_current_state_for_state_machine");
    #endif
}


/* Object Existent */

void adm_object_existent_state(
    const adm_ent_state_typ * const ent_state,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_state");
    #endif

    if (ent_state->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "State",
            ent_state->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_state");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */