
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Simulator Event Acquire Identity Event */

void adm_sim_acquire_identity_event_event_device_update(
    void)
{
    adm_ent_event_typ * ent_event;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_event_device_update");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_event = adm_entity_system.ent_event.live_list_head;

    while (
        entity_not_found &&
        ent_event != NULL) {

        if (ent_event->identity == identity) {

            adm_send_event_event_device_update(
                NULL,
                ent_event,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_event = ent_event->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_event_device_update");
    #endif
}

void adm_sim_acquire_identity_event_event_state_processed(
    void)
{
    adm_ent_event_typ * ent_event;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_event_state_processed");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_event = adm_entity_system.ent_event.live_list_head;

    while (
        entity_not_found &&
        ent_event != NULL) {

        if (ent_event->identity == identity) {

            adm_send_event_event_state_processed(
                NULL,
                ent_event,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_event = ent_event->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_event_state_processed");
    #endif
}

void adm_sim_acquire_identity_event_event_state_not_found(
    void)
{
    adm_ent_event_typ * ent_event;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_event_state_not_found");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_event = adm_entity_system.ent_event.live_list_head;

    while (
        entity_not_found &&
        ent_event != NULL) {

        if (ent_event->identity == identity) {

            adm_send_event_event_state_not_found(
                NULL,
                ent_event,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_event = ent_event->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_event_state_not_found");
    #endif
}

void adm_sim_acquire_identity_event_event_done(
    void)
{
    adm_ent_event_typ * ent_event;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_event_done");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_event = adm_entity_system.ent_event.live_list_head;

    while (
        entity_not_found &&
        ent_event != NULL) {

        if (ent_event->identity == identity) {

            adm_send_event_event_done(
                NULL,
                ent_event,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_event = ent_event->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_event_done");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */