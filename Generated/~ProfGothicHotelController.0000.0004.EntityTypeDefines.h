
/* Entity Type Defines Header */

/* Entity Status Type Defines */

typedef enum {
    ADM_STATUS_EVENT_IDLE,
    ADM_STATUS_EVENT_INITIALISING,
    ADM_STATUS_EVENT_PROCESS_EVENT
} adm_sta_event_typ;

typedef enum {
    ADM_STATUS_TRANSITION_PROCESS_TRANSITION
} adm_sta_transition_typ;

typedef enum {
    ADM_STATUS_STATE_PROCESS_STATE
} adm_sta_state_typ;

typedef enum {
    ADM_STATUS_COMMAND_PROCESS_COMMAND
} adm_sta_command_typ;


/* Entity Event Type Defines */

typedef enum {
    ADM_EVENT_EVENT_DEVICE_UPDATE,
    ADM_EVENT_EVENT_STATE_PROCESSED,
    ADM_EVENT_EVENT_STATE_NOT_FOUND,
    ADM_EVENT_EVENT_DONE
} adm_evt_event_typ;

typedef enum {
    ADM_EVENT_TRANSITION_ACTION_EVENT
} adm_evt_transition_typ;

typedef enum {
    ADM_EVENT_STATE_ACTION_TRANSITION
} adm_evt_state_typ;

typedef enum {
    ADM_EVENT_COMMAND_ACTION_STATE
} adm_evt_command_typ;


/* Entity Type Defines */

/* Event */

typedef struct adm_ent_event {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_event_typ status;
    adm_str_code_name_typ * atb_code;
    struct adm_rel_event_consumed_by_transition * rel_consumed_by_transition_head;
    struct adm_rel_event_consumed_by_transition * rel_consumed_by_transition_tail;
    struct adm_ent_event * back;
    struct adm_ent_event * next;
} adm_ent_event_typ;

/* Transition */

typedef struct adm_ent_transition {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_transition_typ status;
    adm_bln_flag_typ atb_processed;
    struct adm_rel_transition_consumed_by_state * rel_consumed_by_state_head;
    struct adm_rel_transition_consumed_by_state * rel_consumed_by_state_tail;
    struct adm_rel_transition_moves_to_next_state * rel_moves_to_next_state_head;
    struct adm_rel_transition_moves_to_next_state * rel_moves_to_next_state_tail;
    struct adm_rel_transition_determines_current_event * rel_determines_current_event_head;
    struct adm_rel_transition_determines_current_event * rel_determines_current_event_tail;
    struct adm_ent_transition * back;
    struct adm_ent_transition * next;
} adm_ent_transition_typ;

/* State */

typedef struct adm_ent_state {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_state_typ status;
    struct adm_rel_state_invokes_command * rel_invokes_command_head;
    struct adm_rel_state_invokes_command * rel_invokes_command_tail;
    struct adm_rel_state_marks_current_state_for_state_machine * rel_marks_current_state_for_state_machine_head;
    struct adm_rel_state_marks_current_state_for_state_machine * rel_marks_current_state_for_state_machine_tail;
    struct adm_ent_state * back;
    struct adm_ent_state * next;
} adm_ent_state_typ;

/* Command */

typedef struct adm_ent_command {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_command_typ status;
    adm_str_code_name_typ * atb_code;
    struct adm_ent_command * back;
    struct adm_ent_command * next;
} adm_ent_command_typ;

/* State Machine */

typedef struct adm_ent_state_machine {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    struct adm_ent_state_machine * back;
    struct adm_ent_state_machine * next;
} adm_ent_state_machine_typ;


/* Relationship Type Defines */

typedef struct adm_rel_event_consumed_by_transition {
    adm_ent_transition_typ * ent_transition;
    struct adm_rel_event_consumed_by_transition * back;
    struct adm_rel_event_consumed_by_transition * next;
} adm_rel_event_consumed_by_transition_typ;

typedef struct adm_rel_transition_consumed_by_state {
    adm_ent_state_typ * ent_state;
    struct adm_rel_transition_consumed_by_state * back;
    struct adm_rel_transition_consumed_by_state * next;
} adm_rel_transition_consumed_by_state_typ;

typedef struct adm_rel_transition_moves_to_next_state {
    adm_ent_state_typ * ent_state;
    struct adm_rel_transition_moves_to_next_state * back;
    struct adm_rel_transition_moves_to_next_state * next;
} adm_rel_transition_moves_to_next_state_typ;

typedef struct adm_rel_transition_determines_current_event {
    adm_ent_event_typ * ent_event;
    struct adm_rel_transition_determines_current_event * back;
    struct adm_rel_transition_determines_current_event * next;
} adm_rel_transition_determines_current_event_typ;

typedef struct adm_rel_state_invokes_command {
    adm_ent_command_typ * ent_command;
    struct adm_rel_state_invokes_command * back;
    struct adm_rel_state_invokes_command * next;
} adm_rel_state_invokes_command_typ;

typedef struct adm_rel_state_marks_current_state_for_state_machine {
    adm_ent_state_machine_typ * ent_state_machine;
    struct adm_rel_state_marks_current_state_for_state_machine * back;
    struct adm_rel_state_marks_current_state_for_state_machine * next;
} adm_rel_state_marks_current_state_for_state_machine_typ;


/* Error Location Type Define */

typedef struct {
    adm_base_integer_typ file;
    adm_base_integer_typ line;
    adm_base_integer_typ rank;
} adm_error_location_typ;


/* Entity Event Pool Target Type Defines */

typedef struct adm_pool_target_event {
    adm_evt_event_typ evente;
    adm_ent_event_typ * ent_event;
    adm_error_location_typ error_location;
    struct adm_pool_target_event * next;
} adm_pool_target_event_typ;

typedef struct adm_pool_target_transition {
    adm_evt_transition_typ evente;
    adm_ent_transition_typ * ent_transition;
    adm_error_location_typ error_location;
    struct adm_pool_target_transition * next;
} adm_pool_target_transition_typ;

typedef struct adm_pool_target_state {
    adm_evt_state_typ evente;
    adm_ent_state_typ * ent_state;
    adm_error_location_typ error_location;
    struct adm_pool_target_state * next;
} adm_pool_target_state_typ;

typedef struct adm_pool_target_command {
    adm_evt_command_typ evente;
    adm_ent_command_typ * ent_command;
    adm_error_location_typ error_location;
    struct adm_pool_target_command * next;
} adm_pool_target_command_typ;


/* Entity System - Entity Type Defines */

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_event_typ * live_list_head;
    adm_ent_event_typ * live_list_tail;
    adm_ent_event_typ * dead_list_head;
    adm_ent_event_typ * dead_list_tail;
    adm_pool_target_event_typ * home_pool_head;
    adm_pool_target_event_typ * home_pool_tail;
    adm_pool_target_event_typ * away_pool_head;
    adm_pool_target_event_typ * away_pool_tail;
} adm_entity_system_event_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_transition_typ * live_list_head;
    adm_ent_transition_typ * live_list_tail;
    adm_ent_transition_typ * dead_list_head;
    adm_ent_transition_typ * dead_list_tail;
    adm_pool_target_transition_typ * home_pool_head;
    adm_pool_target_transition_typ * home_pool_tail;
    adm_pool_target_transition_typ * away_pool_head;
    adm_pool_target_transition_typ * away_pool_tail;
} adm_entity_system_transition_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_state_typ * live_list_head;
    adm_ent_state_typ * live_list_tail;
    adm_ent_state_typ * dead_list_head;
    adm_ent_state_typ * dead_list_tail;
    adm_pool_target_state_typ * home_pool_head;
    adm_pool_target_state_typ * home_pool_tail;
    adm_pool_target_state_typ * away_pool_head;
    adm_pool_target_state_typ * away_pool_tail;
} adm_entity_system_state_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_command_typ * live_list_head;
    adm_ent_command_typ * live_list_tail;
    adm_ent_command_typ * dead_list_head;
    adm_ent_command_typ * dead_list_tail;
    adm_pool_target_command_typ * home_pool_head;
    adm_pool_target_command_typ * home_pool_tail;
    adm_pool_target_command_typ * away_pool_head;
    adm_pool_target_command_typ * away_pool_tail;
} adm_entity_system_command_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_state_machine_typ * live_list_head;
    adm_ent_state_machine_typ * live_list_tail;
    adm_ent_state_machine_typ * dead_list_head;
    adm_ent_state_machine_typ * dead_list_tail;
} adm_entity_system_state_machine_typ;


/* Entity System - System Type Define */

typedef struct {
    adm_entity_system_event_typ ent_event;
    adm_entity_system_transition_typ ent_transition;
    adm_entity_system_state_typ ent_state;
    adm_entity_system_command_typ ent_command;
    adm_entity_system_state_machine_typ ent_state_machine;
} adm_entity_system_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */