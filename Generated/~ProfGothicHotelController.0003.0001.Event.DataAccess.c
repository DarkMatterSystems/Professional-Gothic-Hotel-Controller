
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Event Data Access */

/* Make Entity Object */

adm_ent_event_typ * adm_make_object_event(
    adm_sta_event_typ status)
{
    adm_ent_event_typ * ent_event;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_event");
    #endif

    if (adm_entity_system.ent_event.dead_list_head != NULL) {

        ent_event = adm_entity_system.ent_event.dead_list_head;

        if (adm_entity_system.ent_event.dead_list_head == ent_event) {

            adm_entity_system.ent_event.dead_list_head = ent_event->next;

        } else {

            (ent_event->back)->next = ent_event->next;
        }

        if (adm_entity_system.ent_event.dead_list_tail == ent_event) {

            adm_entity_system.ent_event.dead_list_tail = ent_event->back;

        } else {

            (ent_event->next)->back = ent_event->back;
        }

    } else {

        ent_event = (adm_ent_event_typ*)adm_allocate_memory(sizeof(adm_ent_event_typ));
    }

    ent_event->identity = ++adm_entity_system.ent_event.tote;

    ent_event->unique  = FALSE;
    ent_event->deleted = FALSE;
    ent_event->marked  = FALSE;
    ent_event->status  = status;

    ent_event->atb_code = (adm_str_code_name_typ*)adm_allocate_memory(ADM_TYPE_SIZE_CODE_NAME+1);

    ent_event->rel_consumed_by_transition_head = NULL;
    ent_event->rel_consumed_by_transition_tail = NULL;

    ent_event->back = NULL;
    ent_event->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_event");
    #endif

    return (ent_event);
}


/* Bind Entity Object */

void adm_bind_object_event(
    adm_ent_event_typ * ent_event,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_event");
    #endif

    adm_object_existent_event(
        ent_event,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_event.live_list_head == NULL) {

        ent_event->back = NULL;

        adm_entity_system.ent_event.live_list_head = ent_event;

    } else {

        ent_event->back = adm_entity_system.ent_event.live_list_tail;

        (adm_entity_system.ent_event.live_list_tail)->next = ent_event;
    }

    ent_event->next = NULL;

    adm_entity_system.ent_event.live_list_tail = ent_event;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_event");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_event(
    void * source_object,
    adm_ent_event_typ * ent_event,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_event");
    #endif

    adm_object_existent_event(
        ent_event,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_event) {

        if (ent_event->rel_consumed_by_transition_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Event",
                ent_event->identity,
                "Consumed_by",
                "Transition");
        }

        if (adm_entity_system.ent_event.live_list_head == ent_event) {

            adm_entity_system.ent_event.live_list_head = ent_event->next;

        } else {

            (ent_event->back)->next = ent_event->next;
        }

        if (adm_entity_system.ent_event.live_list_tail == ent_event) {

            adm_entity_system.ent_event.live_list_tail = ent_event->back;

        } else {

            (ent_event->next)->back = ent_event->back;
        }

        adm_deallocate_memory(ent_event->atb_code);

        ent_event->deleted = TRUE;

        if (adm_entity_system.ent_event.dead_list_head == NULL) {

            ent_event->back = NULL;

            adm_entity_system.ent_event.dead_list_head = ent_event;

        } else {

            ent_event->back = adm_entity_system.ent_event.dead_list_tail;

            (adm_entity_system.ent_event.dead_list_tail)->next = ent_event;
        }

        ent_event->next = NULL;

        adm_entity_system.ent_event.dead_list_tail = ent_event;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Event",
            ent_event->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_event");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_event_consumed_by_transition(
    adm_ent_event_typ * ent_source_event,
    adm_ent_transition_typ * ent_target_transition,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_event_consumed_by_transition_typ * rel_event_consumed_by_transition;

    adm_base_boolean_typ transition_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_event_consumed_by_transition");
    #endif

    adm_object_existent_event(
        ent_source_event,
        error_file,
        error_line,
        error_rank);

    transition_not_found = TRUE;

    rel_event_consumed_by_transition = ent_source_event->rel_consumed_by_transition_head;

    while (
        transition_not_found &&
        rel_event_consumed_by_transition != NULL) {

        if (rel_event_consumed_by_transition->ent_transition == ent_target_transition) {

            transition_not_found = FALSE;
        }

        rel_event_consumed_by_transition = rel_event_consumed_by_transition->next;
    }

    if (transition_not_found) {

        rel_event_consumed_by_transition = (adm_rel_event_consumed_by_transition_typ*)
            adm_allocate_memory(sizeof(adm_rel_event_consumed_by_transition_typ));

        rel_event_consumed_by_transition->ent_transition = ent_target_transition;

        if (ent_source_event->rel_consumed_by_transition_head == NULL) {

            rel_event_consumed_by_transition->back = NULL;

            ent_source_event->rel_consumed_by_transition_head = rel_event_consumed_by_transition;

        } else {

            rel_event_consumed_by_transition->back = ent_source_event->rel_consumed_by_transition_tail;

            (ent_source_event->rel_consumed_by_transition_tail)->next = rel_event_consumed_by_transition;
        }

        rel_event_consumed_by_transition->next = NULL;

        ent_source_event->rel_consumed_by_transition_tail = rel_event_consumed_by_transition;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Event",
            ent_source_event->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_event_consumed_by_transition");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_event_consumed_by_transition(
    adm_ent_event_typ * ent_event,
    adm_rel_event_consumed_by_transition_typ * rel_event_consumed_by_transition,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_event_consumed_by_transition");
    #endif

    adm_object_existent_event(
        ent_event,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_event_consumed_by_transition->next !=
        (adm_base_integer_typ)rel_event_consumed_by_transition->ent_transition) {

        if (ent_event->rel_consumed_by_transition_head != NULL) {

            if (ent_event->rel_consumed_by_transition_head == rel_event_consumed_by_transition) {

                ent_event->rel_consumed_by_transition_head = rel_event_consumed_by_transition->next;

            } else {

                (rel_event_consumed_by_transition->back)->next = rel_event_consumed_by_transition->next;
            }

            if (ent_event->rel_consumed_by_transition_tail == rel_event_consumed_by_transition) {

                ent_event->rel_consumed_by_transition_tail = rel_event_consumed_by_transition->back;

            } else {

                (rel_event_consumed_by_transition->next)->back = rel_event_consumed_by_transition->back;
            }

            adm_deallocate_memory(rel_event_consumed_by_transition);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Event",
                ent_event->identity,
                "Consumed_by",
                "Transition");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Event",
            ent_event->identity,
            "Consumed_by",
            "Transition");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_event_consumed_by_transition");
    #endif
}


/* Object Existent */

void adm_object_existent_event(
    const adm_ent_event_typ * const ent_event,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_event");
    #endif

    if (ent_event->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Event",
            ent_event->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_event");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */