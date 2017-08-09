
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* State State Actions */

void adm_state_action_state_process_state(
    adm_ent_state_typ * const ent_state)
{
    /* Entity Objects */
    adm_ent_command_typ * ent_command_0000000001;

    /* Relationship Relations */
    adm_rel_state_invokes_command_typ * rel_state_invokes_command_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_state_process_state");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_state(
        ent_state,
        4, 18, 29);

    rel_state_invokes_command_0000000001 = ent_state->rel_invokes_command_head;

    while (rel_state_invokes_command_0000000001 != NULL) {

        ent_command_0000000001 = rel_state_invokes_command_0000000001->ent_command;

        /* GenerateEvent */

        adm_send_event_command_action_state(
            ent_state,
            ent_command_0000000001,
            4, 21, 33);

        rel_state_invokes_command_0000000001 = rel_state_invokes_command_0000000001->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_state_process_state");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */