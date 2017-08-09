
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Simulator Transition Acquire Identity Event */

void adm_sim_acquire_identity_event_transition_action_event(
    void)
{
    adm_ent_transition_typ * ent_transition;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_transition_action_event");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_transition = adm_entity_system.ent_transition.live_list_head;

    while (
        entity_not_found &&
        ent_transition != NULL) {

        if (ent_transition->identity == identity) {

            adm_send_event_transition_action_event(
                NULL,
                ent_transition,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_transition = ent_transition->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_transition_action_event");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */