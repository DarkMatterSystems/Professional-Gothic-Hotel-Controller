
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Event Event Senders */

void adm_send_event_event_device_update(
    const void * const source_object,
    const adm_ent_event_typ * const ent_event,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_event_typ * pool_target;
    adm_pool_target_event_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_event_device_update");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_event_device_update(
            ent_event,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_event(
            ent_event,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_event_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_event_typ));

        pool_target->evente = ADM_EVENT_EVENT_DEVICE_UPDATE;
        pool_target->ent_event = (adm_ent_event_typ*)ent_event;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_event) {

            if (adm_entity_system.ent_event.home_pool_head == NULL) {

                adm_entity_system.ent_event.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_event.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_event == ent_event) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Event",
                            ent_event->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_event.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_event.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_event.away_pool_head == NULL) {

                adm_entity_system.ent_event.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_event.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_event.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_event_device_update");
    #endif
}

void adm_send_event_event_state_processed(
    const void * const source_object,
    const adm_ent_event_typ * const ent_event,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_event_typ * pool_target;
    adm_pool_target_event_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_event_state_processed");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_event_state_processed(
            ent_event,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_event(
            ent_event,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_event_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_event_typ));

        pool_target->evente = ADM_EVENT_EVENT_STATE_PROCESSED;
        pool_target->ent_event = (adm_ent_event_typ*)ent_event;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_event) {

            if (adm_entity_system.ent_event.home_pool_head == NULL) {

                adm_entity_system.ent_event.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_event.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_event == ent_event) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Event",
                            ent_event->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_event.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_event.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_event.away_pool_head == NULL) {

                adm_entity_system.ent_event.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_event.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_event.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_event_state_processed");
    #endif
}

void adm_send_event_event_state_not_found(
    const void * const source_object,
    const adm_ent_event_typ * const ent_event,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_event_typ * pool_target;
    adm_pool_target_event_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_event_state_not_found");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_event_state_not_found(
            ent_event,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_event(
            ent_event,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_event_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_event_typ));

        pool_target->evente = ADM_EVENT_EVENT_STATE_NOT_FOUND;
        pool_target->ent_event = (adm_ent_event_typ*)ent_event;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_event) {

            if (adm_entity_system.ent_event.home_pool_head == NULL) {

                adm_entity_system.ent_event.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_event.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_event == ent_event) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Event",
                            ent_event->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_event.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_event.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_event.away_pool_head == NULL) {

                adm_entity_system.ent_event.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_event.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_event.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_event_state_not_found");
    #endif
}

void adm_send_event_event_done(
    const void * const source_object,
    const adm_ent_event_typ * const ent_event,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_event_typ * pool_target;
    adm_pool_target_event_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_event_done");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_event_done(
            ent_event,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_event(
            ent_event,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_event_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_event_typ));

        pool_target->evente = ADM_EVENT_EVENT_DONE;
        pool_target->ent_event = (adm_ent_event_typ*)ent_event;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_event) {

            if (adm_entity_system.ent_event.home_pool_head == NULL) {

                adm_entity_system.ent_event.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_event.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_event == ent_event) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Event",
                            ent_event->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_event.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_event.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_event.away_pool_head == NULL) {

                adm_entity_system.ent_event.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_event.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_event.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_event_done");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */