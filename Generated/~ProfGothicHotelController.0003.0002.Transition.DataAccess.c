
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Transition Data Access */

/* Make Entity Object */

adm_ent_transition_typ * adm_make_object_transition(
    adm_sta_transition_typ status)
{
    adm_ent_transition_typ * ent_transition;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_transition");
    #endif

    if (adm_entity_system.ent_transition.dead_list_head != NULL) {

        ent_transition = adm_entity_system.ent_transition.dead_list_head;

        if (adm_entity_system.ent_transition.dead_list_head == ent_transition) {

            adm_entity_system.ent_transition.dead_list_head = ent_transition->next;

        } else {

            (ent_transition->back)->next = ent_transition->next;
        }

        if (adm_entity_system.ent_transition.dead_list_tail == ent_transition) {

            adm_entity_system.ent_transition.dead_list_tail = ent_transition->back;

        } else {

            (ent_transition->next)->back = ent_transition->back;
        }

    } else {

        ent_transition = (adm_ent_transition_typ*)adm_allocate_memory(sizeof(adm_ent_transition_typ));
    }

    ent_transition->identity = ++adm_entity_system.ent_transition.tote;

    ent_transition->unique  = FALSE;
    ent_transition->deleted = FALSE;
    ent_transition->marked  = FALSE;
    ent_transition->status  = status;

    ent_transition->rel_consumed_by_state_head = NULL;
    ent_transition->rel_consumed_by_state_tail = NULL;

    ent_transition->rel_moves_to_next_state_head = NULL;
    ent_transition->rel_moves_to_next_state_tail = NULL;

    ent_transition->rel_determines_current_event_head = NULL;
    ent_transition->rel_determines_current_event_tail = NULL;

    ent_transition->back = NULL;
    ent_transition->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_transition");
    #endif

    return (ent_transition);
}


/* Bind Entity Object */

void adm_bind_object_transition(
    adm_ent_transition_typ * ent_transition,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_transition");
    #endif

    adm_object_existent_transition(
        ent_transition,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_transition.live_list_head == NULL) {

        ent_transition->back = NULL;

        adm_entity_system.ent_transition.live_list_head = ent_transition;

    } else {

        ent_transition->back = adm_entity_system.ent_transition.live_list_tail;

        (adm_entity_system.ent_transition.live_list_tail)->next = ent_transition;
    }

    ent_transition->next = NULL;

    adm_entity_system.ent_transition.live_list_tail = ent_transition;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_transition");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_transition(
    void * source_object,
    adm_ent_transition_typ * ent_transition,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_transition");
    #endif

    adm_object_existent_transition(
        ent_transition,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_transition) {

        if (ent_transition->rel_consumed_by_state_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Transition",
                ent_transition->identity,
                "Consumed_by",
                "State");
        }

        if (ent_transition->rel_moves_to_next_state_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Transition",
                ent_transition->identity,
                "Moves_to_next",
                "State");
        }

        if (ent_transition->rel_determines_current_event_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Transition",
                ent_transition->identity,
                "Determines_current",
                "Event");
        }

        if (adm_entity_system.ent_transition.live_list_head == ent_transition) {

            adm_entity_system.ent_transition.live_list_head = ent_transition->next;

        } else {

            (ent_transition->back)->next = ent_transition->next;
        }

        if (adm_entity_system.ent_transition.live_list_tail == ent_transition) {

            adm_entity_system.ent_transition.live_list_tail = ent_transition->back;

        } else {

            (ent_transition->next)->back = ent_transition->back;
        }

        ent_transition->deleted = TRUE;

        if (adm_entity_system.ent_transition.dead_list_head == NULL) {

            ent_transition->back = NULL;

            adm_entity_system.ent_transition.dead_list_head = ent_transition;

        } else {

            ent_transition->back = adm_entity_system.ent_transition.dead_list_tail;

            (adm_entity_system.ent_transition.dead_list_tail)->next = ent_transition;
        }

        ent_transition->next = NULL;

        adm_entity_system.ent_transition.dead_list_tail = ent_transition;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Transition",
            ent_transition->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_transition");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_transition_consumed_by_state(
    adm_ent_transition_typ * ent_source_transition,
    adm_ent_state_typ * ent_target_state,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_transition_consumed_by_state_typ * rel_transition_consumed_by_state;

    adm_base_boolean_typ state_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_transition_consumed_by_state");
    #endif

    adm_object_existent_transition(
        ent_source_transition,
        error_file,
        error_line,
        error_rank);

    state_not_found = TRUE;

    rel_transition_consumed_by_state = ent_source_transition->rel_consumed_by_state_head;

    while (
        state_not_found &&
        rel_transition_consumed_by_state != NULL) {

        if (rel_transition_consumed_by_state->ent_state == ent_target_state) {

            state_not_found = FALSE;
        }

        rel_transition_consumed_by_state = rel_transition_consumed_by_state->next;
    }

    if (state_not_found) {

        rel_transition_consumed_by_state = (adm_rel_transition_consumed_by_state_typ*)
            adm_allocate_memory(sizeof(adm_rel_transition_consumed_by_state_typ));

        rel_transition_consumed_by_state->ent_state = ent_target_state;

        if (ent_source_transition->rel_consumed_by_state_head == NULL) {

            rel_transition_consumed_by_state->back = NULL;

            ent_source_transition->rel_consumed_by_state_head = rel_transition_consumed_by_state;

        } else {

            rel_transition_consumed_by_state->back = ent_source_transition->rel_consumed_by_state_tail;

            (ent_source_transition->rel_consumed_by_state_tail)->next = rel_transition_consumed_by_state;
        }

        rel_transition_consumed_by_state->next = NULL;

        ent_source_transition->rel_consumed_by_state_tail = rel_transition_consumed_by_state;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Transition",
            ent_source_transition->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_transition_consumed_by_state");
    #endif
}

void adm_link_relation_transition_moves_to_next_state(
    adm_ent_transition_typ * ent_source_transition,
    adm_ent_state_typ * ent_target_state,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_transition_moves_to_next_state_typ * rel_transition_moves_to_next_state;

    adm_base_boolean_typ state_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_transition_moves_to_next_state");
    #endif

    adm_object_existent_transition(
        ent_source_transition,
        error_file,
        error_line,
        error_rank);

    state_not_found = TRUE;

    rel_transition_moves_to_next_state = ent_source_transition->rel_moves_to_next_state_head;

    while (
        state_not_found &&
        rel_transition_moves_to_next_state != NULL) {

        if (rel_transition_moves_to_next_state->ent_state == ent_target_state) {

            state_not_found = FALSE;
        }

        rel_transition_moves_to_next_state = rel_transition_moves_to_next_state->next;
    }

    if (state_not_found) {

        rel_transition_moves_to_next_state = (adm_rel_transition_moves_to_next_state_typ*)
            adm_allocate_memory(sizeof(adm_rel_transition_moves_to_next_state_typ));

        rel_transition_moves_to_next_state->ent_state = ent_target_state;

        if (ent_source_transition->rel_moves_to_next_state_head == NULL) {

            rel_transition_moves_to_next_state->back = NULL;

            ent_source_transition->rel_moves_to_next_state_head = rel_transition_moves_to_next_state;

        } else {

            rel_transition_moves_to_next_state->back = ent_source_transition->rel_moves_to_next_state_tail;

            (ent_source_transition->rel_moves_to_next_state_tail)->next = rel_transition_moves_to_next_state;
        }

        rel_transition_moves_to_next_state->next = NULL;

        ent_source_transition->rel_moves_to_next_state_tail = rel_transition_moves_to_next_state;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Transition",
            ent_source_transition->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_transition_moves_to_next_state");
    #endif
}

void adm_link_relation_transition_determines_current_event(
    adm_ent_transition_typ * ent_source_transition,
    adm_ent_event_typ * ent_target_event,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_transition_determines_current_event_typ * rel_transition_determines_current_event;

    adm_base_boolean_typ event_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_transition_determines_current_event");
    #endif

    adm_object_existent_transition(
        ent_source_transition,
        error_file,
        error_line,
        error_rank);

    event_not_found = TRUE;

    rel_transition_determines_current_event = ent_source_transition->rel_determines_current_event_head;

    while (
        event_not_found &&
        rel_transition_determines_current_event != NULL) {

        if (rel_transition_determines_current_event->ent_event == ent_target_event) {

            event_not_found = FALSE;
        }

        rel_transition_determines_current_event = rel_transition_determines_current_event->next;
    }

    if (event_not_found) {

        rel_transition_determines_current_event = (adm_rel_transition_determines_current_event_typ*)
            adm_allocate_memory(sizeof(adm_rel_transition_determines_current_event_typ));

        rel_transition_determines_current_event->ent_event = ent_target_event;

        if (ent_source_transition->rel_determines_current_event_head == NULL) {

            rel_transition_determines_current_event->back = NULL;

            ent_source_transition->rel_determines_current_event_head = rel_transition_determines_current_event;

        } else {

            rel_transition_determines_current_event->back = ent_source_transition->rel_determines_current_event_tail;

            (ent_source_transition->rel_determines_current_event_tail)->next = rel_transition_determines_current_event;
        }

        rel_transition_determines_current_event->next = NULL;

        ent_source_transition->rel_determines_current_event_tail = rel_transition_determines_current_event;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Transition",
            ent_source_transition->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_transition_determines_current_event");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_transition_consumed_by_state(
    adm_ent_transition_typ * ent_transition,
    adm_rel_transition_consumed_by_state_typ * rel_transition_consumed_by_state,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_transition_consumed_by_state");
    #endif

    adm_object_existent_transition(
        ent_transition,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_transition_consumed_by_state->next !=
        (adm_base_integer_typ)rel_transition_consumed_by_state->ent_state) {

        if (ent_transition->rel_consumed_by_state_head != NULL) {

            if (ent_transition->rel_consumed_by_state_head == rel_transition_consumed_by_state) {

                ent_transition->rel_consumed_by_state_head = rel_transition_consumed_by_state->next;

            } else {

                (rel_transition_consumed_by_state->back)->next = rel_transition_consumed_by_state->next;
            }

            if (ent_transition->rel_consumed_by_state_tail == rel_transition_consumed_by_state) {

                ent_transition->rel_consumed_by_state_tail = rel_transition_consumed_by_state->back;

            } else {

                (rel_transition_consumed_by_state->next)->back = rel_transition_consumed_by_state->back;
            }

            adm_deallocate_memory(rel_transition_consumed_by_state);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Transition",
                ent_transition->identity,
                "Consumed_by",
                "State");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Transition",
            ent_transition->identity,
            "Consumed_by",
            "State");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_transition_consumed_by_state");
    #endif
}

void adm_kill_relation_transition_moves_to_next_state(
    adm_ent_transition_typ * ent_transition,
    adm_rel_transition_moves_to_next_state_typ * rel_transition_moves_to_next_state,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_transition_moves_to_next_state");
    #endif

    adm_object_existent_transition(
        ent_transition,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_transition_moves_to_next_state->next !=
        (adm_base_integer_typ)rel_transition_moves_to_next_state->ent_state) {

        if (ent_transition->rel_moves_to_next_state_head != NULL) {

            if (ent_transition->rel_moves_to_next_state_head == rel_transition_moves_to_next_state) {

                ent_transition->rel_moves_to_next_state_head = rel_transition_moves_to_next_state->next;

            } else {

                (rel_transition_moves_to_next_state->back)->next = rel_transition_moves_to_next_state->next;
            }

            if (ent_transition->rel_moves_to_next_state_tail == rel_transition_moves_to_next_state) {

                ent_transition->rel_moves_to_next_state_tail = rel_transition_moves_to_next_state->back;

            } else {

                (rel_transition_moves_to_next_state->next)->back = rel_transition_moves_to_next_state->back;
            }

            adm_deallocate_memory(rel_transition_moves_to_next_state);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Transition",
                ent_transition->identity,
                "Moves_to_next",
                "State");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Transition",
            ent_transition->identity,
            "Moves_to_next",
            "State");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_transition_moves_to_next_state");
    #endif
}

void adm_kill_relation_transition_determines_current_event(
    adm_ent_transition_typ * ent_transition,
    adm_rel_transition_determines_current_event_typ * rel_transition_determines_current_event,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_transition_determines_current_event");
    #endif

    adm_object_existent_transition(
        ent_transition,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_transition_determines_current_event->next !=
        (adm_base_integer_typ)rel_transition_determines_current_event->ent_event) {

        if (ent_transition->rel_determines_current_event_head != NULL) {

            if (ent_transition->rel_determines_current_event_head == rel_transition_determines_current_event) {

                ent_transition->rel_determines_current_event_head = rel_transition_determines_current_event->next;

            } else {

                (rel_transition_determines_current_event->back)->next = rel_transition_determines_current_event->next;
            }

            if (ent_transition->rel_determines_current_event_tail == rel_transition_determines_current_event) {

                ent_transition->rel_determines_current_event_tail = rel_transition_determines_current_event->back;

            } else {

                (rel_transition_determines_current_event->next)->back = rel_transition_determines_current_event->back;
            }

            adm_deallocate_memory(rel_transition_determines_current_event);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Transition",
                ent_transition->identity,
                "Determines_current",
                "Event");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Transition",
            ent_transition->identity,
            "Determines_current",
            "Event");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_transition_determines_current_event");
    #endif
}


/* Object Existent */

void adm_object_existent_transition(
    const adm_ent_transition_typ * const ent_transition,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_transition");
    #endif

    if (ent_transition->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Transition",
            ent_transition->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_transition");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */