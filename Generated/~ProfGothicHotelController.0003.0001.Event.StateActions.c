
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Event State Actions */

void adm_state_action_event_idle(
    adm_ent_event_typ * const ent_event)
{
    /* Entity Objects */
    adm_ent_transition_typ * ent_transition_0000000001;

    /* Relationship Relations */
    adm_rel_event_consumed_by_transition_typ * rel_event_consumed_by_transition_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_event_idle");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_event(
        ent_event,
        2, 22, 29);

    rel_event_consumed_by_transition_0000000001 = ent_event->rel_consumed_by_transition_head;

    while (rel_event_consumed_by_transition_0000000001 != NULL) {

        ent_transition_0000000001 = rel_event_consumed_by_transition_0000000001->ent_transition;

        /* Assignment - Set */

        ent_transition_0000000001->atb_processed = FALSE;

        rel_event_consumed_by_transition_0000000001 = rel_event_consumed_by_transition_0000000001->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_event_idle");
    #endif
}

void adm_state_action_event_initialising(
    adm_ent_event_typ * const ent_event)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_event_initialising");
    #endif

    /* GenerateEvent */

    adm_send_event_event_done(
        ent_event,
        ent_event,
        2, 40, 25);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_event_initialising");
    #endif
}

void adm_state_action_event_process_event(
    adm_ent_event_typ * const ent_event)
{
    /* Process Data */
    adm_bln_flag_typ pdt_object_not_found;

    /* Entity Objects */
    adm_ent_transition_typ * ent_transition_0000000001;

    /* Relationship Relations */
    adm_rel_event_consumed_by_transition_typ * rel_event_consumed_by_transition_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_event_process_event");
    #endif

    /* Assignment - Set */

    pdt_object_not_found = TRUE;

    /* Traverse - TraverseSelection */

    adm_object_existent_event(
        ent_event,
        2, 61, 29);

    rel_event_consumed_by_transition_0000000001 = ent_event->rel_consumed_by_transition_head;

    while (rel_event_consumed_by_transition_0000000001 != NULL) {

        ent_transition_0000000001 = rel_event_consumed_by_transition_0000000001->ent_transition;

        /* CaseSelection */

        if (
            (
                (
                    pdt_object_not_found
                )
                &&
                !(
                    ent_transition_0000000001->atb_processed
                )
            )) {

            /* Assignment - Set */

            pdt_object_not_found = FALSE;

            /* Assignment - Set */

            ent_transition_0000000001->atb_processed = TRUE;

            /* Relate */

            adm_link_relation_transition_determines_current_event(
                ent_transition_0000000001,
                ent_event,
                2, 76, 45);

            /* GenerateEvent */

            adm_send_event_transition_action_event(
                ent_event,
                ent_transition_0000000001,
                2, 78, 45);
        }

        rel_event_consumed_by_transition_0000000001 = rel_event_consumed_by_transition_0000000001->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_event_process_event");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */