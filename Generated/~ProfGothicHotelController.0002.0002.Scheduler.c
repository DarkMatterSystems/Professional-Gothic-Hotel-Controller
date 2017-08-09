
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Domain Scheduler */

void adm_scheduler_dom_controller(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_dom_controller");
    #endif

    if (adm_entity_system.ent_event.away_pool_head != NULL) adm_dispatcher_event();
    if (adm_entity_system.ent_transition.away_pool_head != NULL) adm_dispatcher_transition();
    if (adm_entity_system.ent_state.away_pool_head != NULL) adm_dispatcher_state();
    if (adm_entity_system.ent_command.away_pool_head != NULL) adm_dispatcher_command();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_dom_controller");
    #endif
}

adm_base_boolean_typ adm_scheduler_determine_termination_dom_controller(
    void)
{
    adm_base_boolean_typ event_pending;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_determine_termination_dom_controller");
    #endif

    event_pending =
        (adm_entity_system.ent_event.away_pool_head != NULL) ||
        (adm_entity_system.ent_transition.away_pool_head != NULL) ||
        (adm_entity_system.ent_state.away_pool_head != NULL) ||
        (adm_entity_system.ent_command.away_pool_head != NULL);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_determine_termination_dom_controller");
    #endif

    return (event_pending);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */