
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* State Machine Simulator Display Entity */

void adm_sim_display_entity_state_machine(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_state_machine_typ * ent_state_machine;

    adm_sim_width_state_machine_typ width_state_machine;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_state_machine");
    #endif

    width_state_machine.identity = strlen("Identity");

    ent_state_machine = adm_entity_system.ent_state_machine.live_list_head;

    while (ent_state_machine != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_state_machine->identity);
        if (width > width_state_machine.identity) width_state_machine.identity = width;

        ent_state_machine = ent_state_machine->next;
    }

    printf(NEWLINE);
    printf("State_Machine:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_state_machine.identity, "Identity");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_state_machine.identity);

    ent_state_machine = adm_entity_system.ent_state_machine.live_list_head;

    while (ent_state_machine != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_state_machine.identity, ent_state_machine->identity);

        ent_state_machine = ent_state_machine->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_state_machine");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */