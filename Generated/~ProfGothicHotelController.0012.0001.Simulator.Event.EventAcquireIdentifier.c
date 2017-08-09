
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Simulator Event Acquire Identifier Event */

void adm_sim_acquire_identifier_event_event_device_update_event_code_identifier(
    void)
{
    adm_ent_event_typ * ent_event;
    adm_base_boolean_typ entity_not_found;
    adm_base_string_typ key_nme_event_code [ADM_TYPE_SIZE_CODE_NAME+1];

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_event_device_update_event_code_identifier");
    #endif

    /* Fetch Event Keys */

    adm_sim_str_fetch(
        key_nme_event_code,
        ADM_TYPE_SIZE_CODE_NAME+1);

    /* Generate Event */

    entity_not_found = TRUE;

    ent_event = adm_entity_system.ent_event.live_list_head;

    while (
        entity_not_found &&
        ent_event != NULL) {

        if (
            !strcmp(
                ent_event->atb_code, key_nme_event_code)) {

            adm_send_event_event_device_update(
                NULL,
                ent_event,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_event = ent_event->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_event_device_update_event_code_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_event_state_processed_event_code_identifier(
    void)
{
    adm_ent_event_typ * ent_event;
    adm_base_boolean_typ entity_not_found;
    adm_base_string_typ key_nme_event_code [ADM_TYPE_SIZE_CODE_NAME+1];

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_event_state_processed_event_code_identifier");
    #endif

    /* Fetch Event Keys */

    adm_sim_str_fetch(
        key_nme_event_code,
        ADM_TYPE_SIZE_CODE_NAME+1);

    /* Generate Event */

    entity_not_found = TRUE;

    ent_event = adm_entity_system.ent_event.live_list_head;

    while (
        entity_not_found &&
        ent_event != NULL) {

        if (
            !strcmp(
                ent_event->atb_code, key_nme_event_code)) {

            adm_send_event_event_state_processed(
                NULL,
                ent_event,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_event = ent_event->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_event_state_processed_event_code_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_event_state_not_found_event_code_identifier(
    void)
{
    adm_ent_event_typ * ent_event;
    adm_base_boolean_typ entity_not_found;
    adm_base_string_typ key_nme_event_code [ADM_TYPE_SIZE_CODE_NAME+1];

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_event_state_not_found_event_code_identifier");
    #endif

    /* Fetch Event Keys */

    adm_sim_str_fetch(
        key_nme_event_code,
        ADM_TYPE_SIZE_CODE_NAME+1);

    /* Generate Event */

    entity_not_found = TRUE;

    ent_event = adm_entity_system.ent_event.live_list_head;

    while (
        entity_not_found &&
        ent_event != NULL) {

        if (
            !strcmp(
                ent_event->atb_code, key_nme_event_code)) {

            adm_send_event_event_state_not_found(
                NULL,
                ent_event,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_event = ent_event->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_event_state_not_found_event_code_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_event_done_event_code_identifier(
    void)
{
    adm_ent_event_typ * ent_event;
    adm_base_boolean_typ entity_not_found;
    adm_base_string_typ key_nme_event_code [ADM_TYPE_SIZE_CODE_NAME+1];

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_event_done_event_code_identifier");
    #endif

    /* Fetch Event Keys */

    adm_sim_str_fetch(
        key_nme_event_code,
        ADM_TYPE_SIZE_CODE_NAME+1);

    /* Generate Event */

    entity_not_found = TRUE;

    ent_event = adm_entity_system.ent_event.live_list_head;

    while (
        entity_not_found &&
        ent_event != NULL) {

        if (
            !strcmp(
                ent_event->atb_code, key_nme_event_code)) {

            adm_send_event_event_done(
                NULL,
                ent_event,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_event = ent_event->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_event_done_event_code_identifier");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */