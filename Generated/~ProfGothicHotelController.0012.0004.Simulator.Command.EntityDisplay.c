
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Command Simulator Display Entity */

void adm_sim_display_entity_command(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_command_typ * ent_command;

    adm_sim_width_command_typ width_command;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_command");
    #endif

    width_command.identity = strlen("Identity");
    width_command.status = strlen("Status");
    width_command.atb_code = strlen("Code");

    ent_command = adm_entity_system.ent_command.live_list_head;

    while (ent_command != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_command->identity);
        if (width > width_command.identity) width_command.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_command[ent_command->status]);
        if (width > width_command.status) width_command.status = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_command->atb_code);
        if (width > width_command.atb_code) width_command.atb_code = width;

        ent_command = ent_command->next;
    }

    printf(NEWLINE);
    printf("Command:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_command.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_command.status, "Status");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_command.atb_code, "Code");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_command.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_command.status);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_command.atb_code);

    ent_command = adm_entity_system.ent_command.live_list_head;

    while (ent_command != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_command.identity, ent_command->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_command->status) {
            case ADM_STATUS_COMMAND_PROCESS_COMMAND :
                printf("%-*s", width_command.status, "Process_Command");
            break;
            default :
                printf("%-*s", width_command.status, "ERROR");
            break;
        }

        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_command->atb_code);
        printf("%-*s", width_command.atb_code, buffer);

        ent_command = ent_command->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_command");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */