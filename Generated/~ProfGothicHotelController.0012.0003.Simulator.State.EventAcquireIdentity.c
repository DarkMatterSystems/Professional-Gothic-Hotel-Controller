
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Simulator State Acquire Identity Event */

void adm_sim_acquire_identity_event_state_action_transition(
    void)
{
    adm_ent_state_typ * ent_state;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_state_action_transition");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_state = adm_entity_system.ent_state.live_list_head;

    while (
        entity_not_found &&
        ent_state != NULL) {

        if (ent_state->identity == identity) {

            adm_send_event_state_action_transition(
                NULL,
                ent_state,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_state = ent_state->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_state_action_transition");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */