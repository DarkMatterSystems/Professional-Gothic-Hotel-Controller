
/* Simulator System Prototype Internals Header */

/* Display Entity Prototypes */

void adm_sim_display_entity_event(
    void);

void adm_sim_display_entity_transition(
    void);

void adm_sim_display_entity_state(
    void);

void adm_sim_display_entity_command(
    void);

void adm_sim_display_entity_state_machine(
    void);


/* Acquire Identity Event Prototypes */

void adm_sim_acquire_identity_event_event_device_update(
    void);

void adm_sim_acquire_identity_event_event_state_processed(
    void);

void adm_sim_acquire_identity_event_event_state_not_found(
    void);

void adm_sim_acquire_identity_event_event_done(
    void);

void adm_sim_acquire_identity_event_transition_action_event(
    void);

void adm_sim_acquire_identity_event_state_action_transition(
    void);

void adm_sim_acquire_identity_event_command_action_state(
    void);


/* Acquire Identifier Event Prototypes */

void adm_sim_acquire_identifier_event_event_device_update_event_code_identifier(
    void);

void adm_sim_acquire_identifier_event_event_state_processed_event_code_identifier(
    void);

void adm_sim_acquire_identifier_event_event_state_not_found_event_code_identifier(
    void);

void adm_sim_acquire_identifier_event_event_done_event_code_identifier(
    void);


/* Display Event Prototypes */

void adm_sim_display_event_event_device_update(
    const adm_ent_event_typ * const ent_event,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_event_state_processed(
    const adm_ent_event_typ * const ent_event,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_event_state_not_found(
    const adm_ent_event_typ * const ent_event,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_event_done(
    const adm_ent_event_typ * const ent_event,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_transition_action_event(
    const adm_ent_transition_typ * const ent_transition,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_state_action_transition(
    const adm_ent_state_typ * const ent_state,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_command_action_state(
    const adm_ent_command_typ * const ent_command,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);


/* Display State Prototypes */

void adm_sim_display_state_event_idle(
    adm_pool_target_event_typ * pool_target);

void adm_sim_display_state_event_initialising(
    adm_pool_target_event_typ * pool_target);

void adm_sim_display_state_event_process_event(
    adm_pool_target_event_typ * pool_target);

void adm_sim_display_state_transition_process_transition(
    adm_pool_target_transition_typ * pool_target);

void adm_sim_display_state_state_process_state(
    adm_pool_target_state_typ * pool_target);

void adm_sim_display_state_command_process_command(
    adm_pool_target_command_typ * pool_target);


/* Find Event Name Prototype */

adm_base_string_typ * adm_sim_find_event_name(
    adm_base_integer_typ entity_index,
    adm_base_integer_typ entity_event_index);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */