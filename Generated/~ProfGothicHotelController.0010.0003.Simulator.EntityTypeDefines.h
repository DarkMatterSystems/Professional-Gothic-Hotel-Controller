
/* Simulator System Entity Type Defines Header */

/* Domain Enumerations */

typedef enum {
    ADM_SIM_INDEX_DOMAIN_CONTROLLER
} adm_sim_index_domain_typ;

/* Entity Enumerations */

typedef enum {
    ADM_SIM_INDEX_ENTITY_CONTROLLER_EVENT,
    ADM_SIM_INDEX_ENTITY_CONTROLLER_TRANSITION,
    ADM_SIM_INDEX_ENTITY_CONTROLLER_STATE,
    ADM_SIM_INDEX_ENTITY_CONTROLLER_COMMAND,
    ADM_SIM_INDEX_ENTITY_CONTROLLER_STATE_MACHINE
} adm_sim_index_entity_typ;

/* Event Enumerations */

typedef enum {
    ADM_SIM_INDEX_EVENT_CONTROLLER_EVENT_DEVICE_UPDATE,
    ADM_SIM_INDEX_EVENT_CONTROLLER_EVENT_STATE_PROCESSED,
    ADM_SIM_INDEX_EVENT_CONTROLLER_EVENT_STATE_NOT_FOUND,
    ADM_SIM_INDEX_EVENT_CONTROLLER_EVENT_DONE,
    ADM_SIM_INDEX_EVENT_CONTROLLER_TRANSITION_ACTION_EVENT,
    ADM_SIM_INDEX_EVENT_CONTROLLER_STATE_ACTION_TRANSITION,
    ADM_SIM_INDEX_EVENT_CONTROLLER_COMMAND_ACTION_STATE
} adm_sim_index_event_typ;

/* Entity Display Widths */

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
    adm_base_integer_typ atb_code;
} adm_sim_width_event_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
    adm_base_integer_typ atb_processed;
} adm_sim_width_transition_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
} adm_sim_width_state_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
    adm_base_integer_typ atb_code;
} adm_sim_width_command_typ;

typedef struct {
    adm_base_integer_typ identity;
} adm_sim_width_state_machine_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */