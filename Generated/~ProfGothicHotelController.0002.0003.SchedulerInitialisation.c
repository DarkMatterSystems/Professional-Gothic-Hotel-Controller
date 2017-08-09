
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Domain Scheduler Initialisation */

void adm_scheduler_initialisation_controller(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation_controller");
    #endif

    adm_dispatch_home_pool_event();
    adm_dispatch_home_pool_transition();
    adm_dispatch_home_pool_state();
    adm_dispatch_home_pool_command();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation_controller");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */