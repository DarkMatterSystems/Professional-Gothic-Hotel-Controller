
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Command State Actions */

void adm_state_action_command_process_command(
    adm_ent_command_typ * const ent_command)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_command_process_command");
    #endif

    /* Template */

    adm_template_tab_in(5, 15, 21);
    adm_template_tab_in(5, 15, 21);
    adm_write_newline();
    adm_write_str("EVENT => Machinery::Actuator:Device_command (\"");
    adm_write_str(ent_command->atb_code);
    adm_write_str("\")");
    adm_write_newline();
    adm_template_tab_out(5, 15, 21);
    adm_template_tab_out(5, 15, 21);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_command_process_command");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */