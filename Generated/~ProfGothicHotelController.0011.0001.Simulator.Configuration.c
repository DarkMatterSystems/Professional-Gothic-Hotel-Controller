
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Simulator System Configuration */

/* Domain Map */

adm_sim_domain_typ adm_sim_domain[] = {
    {"Controller"},
    {SNULL}
};

/* Entity Map */

adm_sim_entity_typ adm_sim_entity[] = {
    {ADM_SIM_INDEX_DOMAIN_CONTROLLER, "Event", TRUE, adm_sim_display_entity_event},
    {ADM_SIM_INDEX_DOMAIN_CONTROLLER, "Transition", TRUE, adm_sim_display_entity_transition},
    {ADM_SIM_INDEX_DOMAIN_CONTROLLER, "State", TRUE, adm_sim_display_entity_state},
    {ADM_SIM_INDEX_DOMAIN_CONTROLLER, "Command", TRUE, adm_sim_display_entity_command},
    {ADM_SIM_INDEX_DOMAIN_CONTROLLER, "State_Machine", FALSE, adm_sim_display_entity_state_machine},
    {null, SNULL, null, NULL}
};

/* Event Map */

adm_sim_event_typ adm_sim_event[] = {
    {
        ADM_SIM_INDEX_DOMAIN_CONTROLLER,
        ADM_SIM_INDEX_ENTITY_CONTROLLER_EVENT,
        "Device_update",
        FALSE,
        adm_sim_acquire_identity_event_event_device_update
    },
    {
        ADM_SIM_INDEX_DOMAIN_CONTROLLER,
        ADM_SIM_INDEX_ENTITY_CONTROLLER_EVENT,
        "State_processed",
        FALSE,
        adm_sim_acquire_identity_event_event_state_processed
    },
    {
        ADM_SIM_INDEX_DOMAIN_CONTROLLER,
        ADM_SIM_INDEX_ENTITY_CONTROLLER_EVENT,
        "State_not_found",
        FALSE,
        adm_sim_acquire_identity_event_event_state_not_found
    },
    {
        ADM_SIM_INDEX_DOMAIN_CONTROLLER,
        ADM_SIM_INDEX_ENTITY_CONTROLLER_EVENT,
        "Done",
        FALSE,
        adm_sim_acquire_identity_event_event_done
    },
    {
        ADM_SIM_INDEX_DOMAIN_CONTROLLER,
        ADM_SIM_INDEX_ENTITY_CONTROLLER_TRANSITION,
        "Action_event",
        FALSE,
        adm_sim_acquire_identity_event_transition_action_event
    },
    {
        ADM_SIM_INDEX_DOMAIN_CONTROLLER,
        ADM_SIM_INDEX_ENTITY_CONTROLLER_STATE,
        "Action_transition",
        FALSE,
        adm_sim_acquire_identity_event_state_action_transition
    },
    {
        ADM_SIM_INDEX_DOMAIN_CONTROLLER,
        ADM_SIM_INDEX_ENTITY_CONTROLLER_COMMAND,
        "Action_state",
        FALSE,
        adm_sim_acquire_identity_event_command_action_state
    },
    {
        null,
        null,
        SNULL,
        null,
        NULL
    }
};

/* Identifier Map */

adm_sim_identifier_typ adm_sim_identifier[] = {
    {
        ADM_SIM_INDEX_DOMAIN_CONTROLLER,
        ADM_SIM_INDEX_ENTITY_CONTROLLER_EVENT,
        ADM_SIM_INDEX_EVENT_CONTROLLER_EVENT_DEVICE_UPDATE,
        "Event_Code_Identifier",
        adm_sim_acquire_identifier_event_event_device_update_event_code_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_CONTROLLER,
        ADM_SIM_INDEX_ENTITY_CONTROLLER_EVENT,
        ADM_SIM_INDEX_EVENT_CONTROLLER_EVENT_STATE_PROCESSED,
        "Event_Code_Identifier",
        adm_sim_acquire_identifier_event_event_state_processed_event_code_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_CONTROLLER,
        ADM_SIM_INDEX_ENTITY_CONTROLLER_EVENT,
        ADM_SIM_INDEX_EVENT_CONTROLLER_EVENT_STATE_NOT_FOUND,
        "Event_Code_Identifier",
        adm_sim_acquire_identifier_event_event_state_not_found_event_code_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_CONTROLLER,
        ADM_SIM_INDEX_ENTITY_CONTROLLER_EVENT,
        ADM_SIM_INDEX_EVENT_CONTROLLER_EVENT_DONE,
        "Event_Code_Identifier",
        adm_sim_acquire_identifier_event_event_done_event_code_identifier
    },
    {
        null,
        null,
        null,
        SNULL,
        NULL
    }
};


/* Find Event Name From Event Index */

adm_base_string_typ * adm_sim_find_event_name(
    adm_base_integer_typ entity_index,
    adm_base_integer_typ entity_event_index)
{
    adm_base_integer_typ index;

    adm_base_boolean_typ event_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_find_event_name");
    #endif

    index = 0;

    event_not_found = TRUE;

    while (event_not_found) {

        if (adm_sim_event[index].entity == entity_index) {

            index += entity_event_index;

            event_not_found = FALSE;

        } else {

            ++index;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_find_event_name");
    #endif

    return (adm_sim_event[index].name);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */