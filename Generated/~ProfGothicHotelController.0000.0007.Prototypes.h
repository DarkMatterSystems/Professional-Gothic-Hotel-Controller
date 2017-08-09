
/* System Prototypes Header */

/* Main Prototype */

int main(
    int,
    char * []);


/* System Library */

void * adm_allocate_memory(
    adm_base_integer_typ amount);

void adm_deallocate_memory(
    const void * memory);

void adm_open_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_close_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_write_int(
    adm_base_integer_typ number);

void adm_write_bln(
    adm_base_boolean_typ value);

void adm_write_fxd(
    adm_base_fixed_typ number);

void adm_write_flt(
    adm_base_float_typ number);

void adm_write_str(
    const adm_base_string_typ * const string);

void adm_write_newline(void);

void adm_template_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_template_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_display_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_display_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_convert_string_upper_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_lower_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_sentence_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_capital_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_remove_spaces(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_convert_underlines(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_integrity_check(void);


#if ADM_PROBE

void adm_probe_enter(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name);

void adm_probe_leave(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name);

void adm_add_spaces(
    adm_base_string_typ  * space_string,
    adm_base_integer_typ   space_number);

#endif


/* System Error Handler */

void adm_error_report(
    adm_err_number_typ          error,
    adm_err_file_typ            file,
    adm_err_line_typ            line,
    adm_err_rank_typ            rank,
    adm_err_problem_typ       * source,
    adm_base_integer_typ        identity,
    adm_err_problem_typ       * relation,
    const adm_err_problem_typ * target);


/* Initialisation Prototype */

void adm_initialisation(void);


/* Domain Initialisation Prototypes */

void adm_initialisation_controller(void);


/* System Scheduler Prototypes */

void adm_scheduler(void);

void adm_scheduler_dom_controller(void);


/* System Initialisation Scheduler Prototypes */

void adm_scheduler_initialisation(void);

void adm_scheduler_initialisation_controller(void);


/* System Determine Termination Scheduler Prototypes */

adm_base_boolean_typ adm_scheduler_determine_termination(void);

adm_base_boolean_typ adm_scheduler_determine_termination_dom_controller(void);


/* Data Access Prototypes */

adm_ent_event_typ * adm_make_object_event(
    adm_sta_event_typ status);

adm_ent_transition_typ * adm_make_object_transition(
    adm_sta_transition_typ status);

adm_ent_state_typ * adm_make_object_state(
    adm_sta_state_typ status);

adm_ent_command_typ * adm_make_object_command(
    adm_sta_command_typ status);

adm_ent_state_machine_typ * adm_make_object_state_machine(void);

void adm_bind_object_event(
    adm_ent_event_typ * ent_event,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_transition(
    adm_ent_transition_typ * ent_transition,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_state(
    adm_ent_state_typ * ent_state,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_command(
    adm_ent_command_typ * ent_command,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_state_machine(
    adm_ent_state_machine_typ * ent_state_machine,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_event(
    void * source_object,
    adm_ent_event_typ * ent_event,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_transition(
    void * source_object,
    adm_ent_transition_typ * ent_transition,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_state(
    void * source_object,
    adm_ent_state_typ * ent_state,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_command(
    void * source_object,
    adm_ent_command_typ * ent_command,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_state_machine(
    void * source_object,
    adm_ent_state_machine_typ * ent_state_machine,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_event_consumed_by_transition(
    adm_ent_event_typ * ent_source_event,
    adm_ent_transition_typ * ent_target_transition,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_transition_consumed_by_state(
    adm_ent_transition_typ * ent_source_transition,
    adm_ent_state_typ * ent_target_state,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_transition_moves_to_next_state(
    adm_ent_transition_typ * ent_source_transition,
    adm_ent_state_typ * ent_target_state,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_transition_determines_current_event(
    adm_ent_transition_typ * ent_source_transition,
    adm_ent_event_typ * ent_target_event,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_state_invokes_command(
    adm_ent_state_typ * ent_source_state,
    adm_ent_command_typ * ent_target_command,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_state_marks_current_state_for_state_machine(
    adm_ent_state_typ * ent_source_state,
    adm_ent_state_machine_typ * ent_target_state_machine,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_event_consumed_by_transition(
    adm_ent_event_typ * ent_event,
    adm_rel_event_consumed_by_transition_typ * rel_event_consumed_by_transition,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_transition_consumed_by_state(
    adm_ent_transition_typ * ent_transition,
    adm_rel_transition_consumed_by_state_typ * rel_transition_consumed_by_state,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_transition_moves_to_next_state(
    adm_ent_transition_typ * ent_transition,
    adm_rel_transition_moves_to_next_state_typ * rel_transition_moves_to_next_state,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_transition_determines_current_event(
    adm_ent_transition_typ * ent_transition,
    adm_rel_transition_determines_current_event_typ * rel_transition_determines_current_event,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_state_invokes_command(
    adm_ent_state_typ * ent_state,
    adm_rel_state_invokes_command_typ * rel_state_invokes_command,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_state_marks_current_state_for_state_machine(
    adm_ent_state_typ * ent_state,
    adm_rel_state_marks_current_state_for_state_machine_typ * rel_state_marks_current_state_for_state_machine,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_event(
    const adm_ent_event_typ * const ent_event,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_transition(
    const adm_ent_transition_typ * const ent_transition,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_state(
    const adm_ent_state_typ * const ent_state,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_command(
    const adm_ent_command_typ * const ent_command,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_state_machine(
    const adm_ent_state_machine_typ * const ent_state_machine,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);


/* Event Sender Prototypes */

void adm_send_event_event_device_update(
    const void * const source_object,
    const adm_ent_event_typ * const ent_event,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_event_state_processed(
    const void * const source_object,
    const adm_ent_event_typ * const ent_event,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_event_state_not_found(
    const void * const source_object,
    const adm_ent_event_typ * const ent_event,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_event_done(
    const void * const source_object,
    const adm_ent_event_typ * const ent_event,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_transition_action_event(
    const void * const source_object,
    const adm_ent_transition_typ * const ent_transition,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_state_action_transition(
    const void * const source_object,
    const adm_ent_state_typ * const ent_state,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_command_action_state(
    const void * const source_object,
    const adm_ent_command_typ * const ent_command,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);


/* Dispatcher Prototypes */

void adm_dispatcher_event         (void);
void adm_dispatch_home_pool_event (void);

adm_pool_target_event_typ * adm_find_home_target_event_event (void);
adm_pool_target_event_typ * adm_find_away_target_event_event (void);

void adm_dispatch_state_action_event(
    adm_pool_target_event_typ * pool_target_event);

void adm_dispatcher_transition         (void);
void adm_dispatch_home_pool_transition (void);

adm_pool_target_transition_typ * adm_find_home_target_event_transition (void);
adm_pool_target_transition_typ * adm_find_away_target_event_transition (void);

void adm_dispatch_state_action_transition(
    adm_pool_target_transition_typ * pool_target_transition);

void adm_dispatcher_state         (void);
void adm_dispatch_home_pool_state (void);

adm_pool_target_state_typ * adm_find_home_target_event_state (void);
adm_pool_target_state_typ * adm_find_away_target_event_state (void);

void adm_dispatch_state_action_state(
    adm_pool_target_state_typ * pool_target_state);

void adm_dispatcher_command         (void);
void adm_dispatch_home_pool_command (void);

adm_pool_target_command_typ * adm_find_home_target_event_command (void);
adm_pool_target_command_typ * adm_find_away_target_event_command (void);

void adm_dispatch_state_action_command(
    adm_pool_target_command_typ * pool_target_command);


/* State Action Prototypes */

void adm_state_action_event_idle(
    adm_ent_event_typ * const ent_event);

void adm_state_action_event_initialising(
    adm_ent_event_typ * const ent_event);

void adm_state_action_event_process_event(
    adm_ent_event_typ * const ent_event);

void adm_state_action_transition_process_transition(
    adm_ent_transition_typ * const ent_transition);

void adm_state_action_state_process_state(
    adm_ent_state_typ * const ent_state);

void adm_state_action_command_process_command(
    adm_ent_command_typ * const ent_command);


/* Identifier Prototypes */

void adm_check_identifiers_unique_event(
    adm_ent_event_typ * ent_source_event,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */