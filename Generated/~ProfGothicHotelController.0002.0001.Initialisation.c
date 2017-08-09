
#include "~ProfGothicHotelController.0000.0000.Header.h"


/* Domain - Initialisation */

void adm_initialisation_controller(
    void)
{
    /* Declare Objects */

    /* Event */
    adm_ent_event_typ * ent_event_0000000001;
    adm_ent_event_typ * ent_event_0000000002;
    adm_ent_event_typ * ent_event_0000000003;
    adm_ent_event_typ * ent_event_0000000004;
    adm_ent_event_typ * ent_event_0000000005;

    /* Transition */
    adm_ent_transition_typ * ent_transition_0000000006;
    adm_ent_transition_typ * ent_transition_0000000007;
    adm_ent_transition_typ * ent_transition_0000000008;
    adm_ent_transition_typ * ent_transition_0000000009;
    adm_ent_transition_typ * ent_transition_0000000010;
    adm_ent_transition_typ * ent_transition_0000000011;
    adm_ent_transition_typ * ent_transition_0000000012;
    adm_ent_transition_typ * ent_transition_0000000013;
    adm_ent_transition_typ * ent_transition_0000000014;
    adm_ent_transition_typ * ent_transition_0000000015;
    adm_ent_transition_typ * ent_transition_0000000016;
    adm_ent_transition_typ * ent_transition_0000000017;
    adm_ent_transition_typ * ent_transition_0000000018;
    adm_ent_transition_typ * ent_transition_0000000019;
    adm_ent_transition_typ * ent_transition_0000000020;
    adm_ent_transition_typ * ent_transition_0000000021;

    /* State */
    adm_ent_state_typ * ent_state_0000000022;
    adm_ent_state_typ * ent_state_0000000023;
    adm_ent_state_typ * ent_state_0000000024;
    adm_ent_state_typ * ent_state_0000000025;
    adm_ent_state_typ * ent_state_0000000026;

    /* Command */
    adm_ent_command_typ * ent_command_0000000027;
    adm_ent_command_typ * ent_command_0000000028;
    adm_ent_command_typ * ent_command_0000000029;
    adm_ent_command_typ * ent_command_0000000030;

    /* State Machine */
    adm_ent_state_machine_typ * ent_state_machine_0000000031;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation_controller");
    #endif

    /* Entity System */

    adm_entity_system.ent_event.tote = 0;
    adm_entity_system.ent_transition.tote = 0;
    adm_entity_system.ent_state.tote = 0;
    adm_entity_system.ent_command.tote = 0;
    adm_entity_system.ent_state_machine.tote = 0;

    adm_entity_system.ent_event.live_list_head = NULL;
    adm_entity_system.ent_transition.live_list_head = NULL;
    adm_entity_system.ent_state.live_list_head = NULL;
    adm_entity_system.ent_command.live_list_head = NULL;
    adm_entity_system.ent_state_machine.live_list_head = NULL;

    adm_entity_system.ent_event.live_list_tail = NULL;
    adm_entity_system.ent_transition.live_list_tail = NULL;
    adm_entity_system.ent_state.live_list_tail = NULL;
    adm_entity_system.ent_command.live_list_tail = NULL;
    adm_entity_system.ent_state_machine.live_list_tail = NULL;

    adm_entity_system.ent_event.dead_list_head = NULL;
    adm_entity_system.ent_transition.dead_list_head = NULL;
    adm_entity_system.ent_state.dead_list_head = NULL;
    adm_entity_system.ent_command.dead_list_head = NULL;
    adm_entity_system.ent_state_machine.dead_list_head = NULL;

    adm_entity_system.ent_event.dead_list_tail = NULL;
    adm_entity_system.ent_transition.dead_list_tail = NULL;
    adm_entity_system.ent_state.dead_list_tail = NULL;
    adm_entity_system.ent_command.dead_list_tail = NULL;
    adm_entity_system.ent_state_machine.dead_list_tail = NULL;

    adm_entity_system.ent_event.home_pool_head = NULL;
    adm_entity_system.ent_transition.home_pool_head = NULL;
    adm_entity_system.ent_state.home_pool_head = NULL;
    adm_entity_system.ent_command.home_pool_head = NULL;

    adm_entity_system.ent_event.home_pool_tail = NULL;
    adm_entity_system.ent_transition.home_pool_tail = NULL;
    adm_entity_system.ent_state.home_pool_tail = NULL;
    adm_entity_system.ent_command.home_pool_tail = NULL;

    adm_entity_system.ent_event.away_pool_head = NULL;
    adm_entity_system.ent_transition.away_pool_head = NULL;
    adm_entity_system.ent_state.away_pool_head = NULL;
    adm_entity_system.ent_command.away_pool_head = NULL;

    adm_entity_system.ent_event.away_pool_tail = NULL;
    adm_entity_system.ent_transition.away_pool_tail = NULL;
    adm_entity_system.ent_state.away_pool_tail = NULL;
    adm_entity_system.ent_command.away_pool_tail = NULL;


    /* Make Objects */

    /* Event */
    ent_event_0000000001 = adm_make_object_event(ADM_STATUS_EVENT_IDLE);
    ent_event_0000000002 = adm_make_object_event(ADM_STATUS_EVENT_IDLE);
    ent_event_0000000003 = adm_make_object_event(ADM_STATUS_EVENT_IDLE);
    ent_event_0000000004 = adm_make_object_event(ADM_STATUS_EVENT_IDLE);
    ent_event_0000000005 = adm_make_object_event(ADM_STATUS_EVENT_IDLE);

    /* Transition */
    ent_transition_0000000006 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000007 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000008 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000009 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000010 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000011 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000012 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000013 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000014 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000015 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000016 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000017 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000018 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000019 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000020 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);
    ent_transition_0000000021 = adm_make_object_transition(ADM_STATUS_TRANSITION_PROCESS_TRANSITION);

    /* State */
    ent_state_0000000022 = adm_make_object_state(ADM_STATUS_STATE_PROCESS_STATE);
    ent_state_0000000023 = adm_make_object_state(ADM_STATUS_STATE_PROCESS_STATE);
    ent_state_0000000024 = adm_make_object_state(ADM_STATUS_STATE_PROCESS_STATE);
    ent_state_0000000025 = adm_make_object_state(ADM_STATUS_STATE_PROCESS_STATE);
    ent_state_0000000026 = adm_make_object_state(ADM_STATUS_STATE_PROCESS_STATE);

    /* Command */
    ent_command_0000000027 = adm_make_object_command(ADM_STATUS_COMMAND_PROCESS_COMMAND);
    ent_command_0000000028 = adm_make_object_command(ADM_STATUS_COMMAND_PROCESS_COMMAND);
    ent_command_0000000029 = adm_make_object_command(ADM_STATUS_COMMAND_PROCESS_COMMAND);
    ent_command_0000000030 = adm_make_object_command(ADM_STATUS_COMMAND_PROCESS_COMMAND);

    /* State Machine */
    ent_state_machine_0000000031 = adm_make_object_state_machine();


    /* Object Fact Assignments */

    /* Event */

    strcpy_s(ent_event_0000000001->atb_code, ADM_TYPE_SIZE_CODE_NAME+1,(adm_str_code_name_typ*)&"D1CL");

    strcpy_s(ent_event_0000000002->atb_code, ADM_TYPE_SIZE_CODE_NAME+1,(adm_str_code_name_typ*)&"L1ON");

    strcpy_s(ent_event_0000000003->atb_code, ADM_TYPE_SIZE_CODE_NAME+1,(adm_str_code_name_typ*)&"D2OP");

    strcpy_s(ent_event_0000000004->atb_code, ADM_TYPE_SIZE_CODE_NAME+1,(adm_str_code_name_typ*)&"PNCL");

    strcpy_s(ent_event_0000000005->atb_code, ADM_TYPE_SIZE_CODE_NAME+1,(adm_str_code_name_typ*)&"D1OP");

    /* Transition */

    ent_transition_0000000006->atb_processed = FALSE;

    ent_transition_0000000007->atb_processed = FALSE;

    ent_transition_0000000008->atb_processed = FALSE;

    ent_transition_0000000009->atb_processed = FALSE;

    ent_transition_0000000010->atb_processed = FALSE;

    ent_transition_0000000011->atb_processed = FALSE;

    ent_transition_0000000012->atb_processed = FALSE;

    ent_transition_0000000013->atb_processed = FALSE;

    ent_transition_0000000014->atb_processed = FALSE;

    ent_transition_0000000015->atb_processed = FALSE;

    ent_transition_0000000016->atb_processed = FALSE;

    ent_transition_0000000017->atb_processed = FALSE;

    ent_transition_0000000018->atb_processed = FALSE;

    ent_transition_0000000019->atb_processed = FALSE;

    ent_transition_0000000020->atb_processed = FALSE;

    ent_transition_0000000021->atb_processed = FALSE;

    /* Command */

    strcpy_s(ent_command_0000000027->atb_code, ADM_TYPE_SIZE_CODE_NAME+1,(adm_str_code_name_typ*)&"D1LK");

    strcpy_s(ent_command_0000000028->atb_code, ADM_TYPE_SIZE_CODE_NAME+1,(adm_str_code_name_typ*)&"D1UL");

    strcpy_s(ent_command_0000000029->atb_code, ADM_TYPE_SIZE_CODE_NAME+1,(adm_str_code_name_typ*)&"PNLK");

    strcpy_s(ent_command_0000000030->atb_code, ADM_TYPE_SIZE_CODE_NAME+1,(adm_str_code_name_typ*)&"PNUL");


    /* Bind Objects */

    /* Event */
    adm_bind_object_event(
        ent_event_0000000001,
        6, 15, 25);
    adm_bind_object_event(
        ent_event_0000000002,
        6, 16, 25);
    adm_bind_object_event(
        ent_event_0000000003,
        6, 17, 25);
    adm_bind_object_event(
        ent_event_0000000004,
        6, 18, 25);
    adm_bind_object_event(
        ent_event_0000000005,
        6, 19, 25);

    /* Transition */
    adm_bind_object_transition(
        ent_transition_0000000006,
        6, 43, 25);
    adm_bind_object_transition(
        ent_transition_0000000007,
        6, 44, 25);
    adm_bind_object_transition(
        ent_transition_0000000008,
        6, 45, 25);
    adm_bind_object_transition(
        ent_transition_0000000009,
        6, 46, 25);
    adm_bind_object_transition(
        ent_transition_0000000010,
        6, 47, 25);
    adm_bind_object_transition(
        ent_transition_0000000011,
        6, 48, 25);
    adm_bind_object_transition(
        ent_transition_0000000012,
        6, 49, 25);
    adm_bind_object_transition(
        ent_transition_0000000013,
        6, 50, 25);
    adm_bind_object_transition(
        ent_transition_0000000014,
        6, 51, 25);
    adm_bind_object_transition(
        ent_transition_0000000015,
        6, 52, 25);
    adm_bind_object_transition(
        ent_transition_0000000016,
        6, 53, 25);
    adm_bind_object_transition(
        ent_transition_0000000017,
        6, 54, 25);
    adm_bind_object_transition(
        ent_transition_0000000018,
        6, 55, 25);
    adm_bind_object_transition(
        ent_transition_0000000019,
        6, 56, 25);
    adm_bind_object_transition(
        ent_transition_0000000020,
        6, 57, 25);
    adm_bind_object_transition(
        ent_transition_0000000021,
        6, 58, 25);

    /* State */
    adm_bind_object_state(
        ent_state_0000000022,
        6, 99, 25);
    adm_bind_object_state(
        ent_state_0000000023,
        6, 100, 25);
    adm_bind_object_state(
        ent_state_0000000024,
        6, 101, 25);
    adm_bind_object_state(
        ent_state_0000000025,
        6, 102, 25);
    adm_bind_object_state(
        ent_state_0000000026,
        6, 103, 25);

    /* Command */
    adm_bind_object_command(
        ent_command_0000000027,
        6, 117, 25);
    adm_bind_object_command(
        ent_command_0000000028,
        6, 118, 25);
    adm_bind_object_command(
        ent_command_0000000029,
        6, 119, 25);
    adm_bind_object_command(
        ent_command_0000000030,
        6, 120, 25);

    /* State Machine */
    adm_bind_object_state_machine(
        ent_state_machine_0000000031,
        6, 127, 25);


    /* Link Relations */

    /* Event */

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000001,
        ent_transition_0000000006,
        6, 21, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000002,
        ent_transition_0000000007,
        6, 22, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000002,
        ent_transition_0000000008,
        6, 23, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000002,
        ent_transition_0000000009,
        6, 24, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000003,
        ent_transition_0000000010,
        6, 25, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000003,
        ent_transition_0000000011,
        6, 26, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000003,
        ent_transition_0000000012,
        6, 27, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000004,
        ent_transition_0000000013,
        6, 28, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000004,
        ent_transition_0000000014,
        6, 29, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000004,
        ent_transition_0000000015,
        6, 30, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000004,
        ent_transition_0000000016,
        6, 31, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000004,
        ent_transition_0000000017,
        6, 32, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000005,
        ent_transition_0000000018,
        6, 33, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000005,
        ent_transition_0000000019,
        6, 34, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000005,
        ent_transition_0000000020,
        6, 35, 25);

    adm_link_relation_event_consumed_by_transition(
        ent_event_0000000005,
        ent_transition_0000000021,
        6, 36, 25);

    /* Transition */

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000006,
        ent_state_0000000022,
        6, 60, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000007,
        ent_state_0000000023,
        6, 61, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000008,
        ent_state_0000000024,
        6, 62, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000009,
        ent_state_0000000025,
        6, 63, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000010,
        ent_state_0000000023,
        6, 64, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000011,
        ent_state_0000000024,
        6, 65, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000012,
        ent_state_0000000025,
        6, 66, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000013,
        ent_state_0000000022,
        6, 67, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000014,
        ent_state_0000000023,
        6, 68, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000015,
        ent_state_0000000024,
        6, 69, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000016,
        ent_state_0000000025,
        6, 70, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000017,
        ent_state_0000000026,
        6, 71, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000018,
        ent_state_0000000023,
        6, 72, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000019,
        ent_state_0000000024,
        6, 73, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000020,
        ent_state_0000000025,
        6, 74, 25);

    adm_link_relation_transition_consumed_by_state(
        ent_transition_0000000021,
        ent_state_0000000026,
        6, 75, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000006,
        ent_state_0000000023,
        6, 77, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000007,
        ent_state_0000000025,
        6, 78, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000008,
        ent_state_0000000026,
        6, 79, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000009,
        ent_state_0000000022,
        6, 80, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000010,
        ent_state_0000000024,
        6, 81, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000011,
        ent_state_0000000022,
        6, 82, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000012,
        ent_state_0000000026,
        6, 83, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000013,
        ent_state_0000000022,
        6, 84, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000014,
        ent_state_0000000022,
        6, 85, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000015,
        ent_state_0000000022,
        6, 86, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000016,
        ent_state_0000000022,
        6, 87, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000017,
        ent_state_0000000022,
        6, 88, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000018,
        ent_state_0000000022,
        6, 89, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000019,
        ent_state_0000000022,
        6, 90, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000020,
        ent_state_0000000022,
        6, 91, 25);

    adm_link_relation_transition_moves_to_next_state(
        ent_transition_0000000021,
        ent_state_0000000022,
        6, 92, 25);

    /* State */

    adm_link_relation_state_invokes_command(
        ent_state_0000000022,
        ent_command_0000000029,
        6, 107, 25);

    adm_link_relation_state_invokes_command(
        ent_state_0000000022,
        ent_command_0000000028,
        6, 108, 25);

    adm_link_relation_state_invokes_command(
        ent_state_0000000026,
        ent_command_0000000027,
        6, 109, 25);

    adm_link_relation_state_invokes_command(
        ent_state_0000000026,
        ent_command_0000000030,
        6, 110, 25);

    adm_link_relation_state_marks_current_state_for_state_machine(
        ent_state_0000000022,
        ent_state_machine_0000000031,
        6, 105, 25);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation_controller");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */