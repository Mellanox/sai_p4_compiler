/* *
 * @file    saiexample.h
 *
 * @brief   This module defines SAI || P4 extension  interface
 */

#if !defined (__SAIEXAMPLE_H_)
#define __SAIEXAMPLE_H_

#include <saitypes.h>

sai_status_t sai_ext_api_initialize(sai_object_list_t in_port_if_list);
sai_status_t sai_ext_api_uninitialize(sai_object_list_t in_port_if_list);

/**
 * @defgroup SAIEXAMPLE SAI - Extension specific API definitions
 *
 * @{
 */

/**
 * @brief Attribute data for #SAI_CONTROL_IN_PORT_TABLE_EX1_ENTRY_ATTR_ACTION
 */
typedef enum _sai_control_in_port_table_ex1_entry_action_t
{
    SAI_CONTROL_IN_PORT_TABLE_EX1_ENTRY_ACTION_CONTROL_IN_PORT_SET_BRIDGE,

    SAI_CONTROL_IN_PORT_TABLE_EX1_ENTRY_ACTION_NOACTION,

} sai_control_in_port_table_ex1_entry_action_t;

/**
 * @brief Attribute data for #SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ATTR_ACTION
 */
typedef enum _sai_control_in_port_table_ex2_entry_action_t
{
    SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ACTION_CONTROL_IN_PORT_TO_ROUTER,

    SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ACTION_CONTROL_IN_PORT_TO_PORT,

    SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ACTION_NOACTION,

} sai_control_in_port_table_ex2_entry_action_t;

/**
 * @brief Attribute ID for control_in_port_table_ex1
 */
typedef enum _sai_control_in_port_table_ex1_entry_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_CONTROL_IN_PORT_TABLE_EX1_ENTRY_ATTR_START,

    /**
     * @brief Action
     *
     * @type sai_control_in_port_table_ex1_entry_action_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_CONTROL_IN_PORT_TABLE_EX1_ENTRY_ATTR_ACTION = SAI_CONTROL_IN_PORT_TABLE_EX1_ENTRY_ATTR_START,

    /**
     * @brief Matched key in_port
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_PORT
     */
    SAI_CONTROL_IN_PORT_TABLE_EX1_ENTRY_ATTR_IN_PORT,

    /**
     * @brief Is default entry
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_CONTROL_IN_PORT_TABLE_EX1_ENTRY_ATTR_IS_DEFAULT,

    /**
     * @brief Action CONTROL_IN_PORT_SET_BRIDGE parameter bridge_id
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_BRIDGE
     * @condition SAI_CONTROL_IN_PORT_TABLE_EX1_ENTRY_ATTR_ACTION == SAI_CONTROL_IN_PORT_TABLE_EX1_ENTRY_ACTION_CONTROL_IN_PORT_SET_BRIDGE
     */
    SAI_CONTROL_IN_PORT_TABLE_EX1_ENTRY_ATTR_BRIDGE_ID,

    /**
     * @brief End of attributes
     */
    SAI_CONTROL_IN_PORT_TABLE_EX1_ENTRY_ATTR_END,

    /** Custom range base value */
    SAI_CONTROL_IN_PORT_TABLE_EX1_ENTRY_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_CONTROL_IN_PORT_TABLE_EX1_ENTRY_ATTR_CUSTOM_RANGE_END,

} sai_control_in_port_table_ex1_entry_attr_t;

/**
 * @brief Attribute ID for control_in_port_table_ex2
 */
typedef enum _sai_control_in_port_table_ex2_entry_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ATTR_START,

    /**
     * @brief Action
     *
     * @type sai_control_in_port_table_ex2_entry_action_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ATTR_ACTION = SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ATTR_START,

    /**
     * @brief Matched key dst_ip
     *
     * @type sai_ip_address_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ATTR_DST_IP,

    /**
     * @brief Is default entry
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ATTR_IS_DEFAULT,

    /**
     * @brief Action CONTROL_IN_PORT_TO_ROUTER parameter vr_id
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_VIRTUAL_ROUTER
     * @condition SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ATTR_ACTION == SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ACTION_CONTROL_IN_PORT_TO_ROUTER
     */
    SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ATTR_VR_ID,

    /**
     * @brief Action CONTROL_IN_PORT_TO_PORT parameter port_id
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_PORT
     * @condition SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ATTR_ACTION == SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ACTION_CONTROL_IN_PORT_TO_PORT
     */
    SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ATTR_PORT_ID,

    /**
     * @brief End of attributes
     */
    SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ATTR_END,

    /** Custom range base value */
    SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_CONTROL_IN_PORT_TABLE_EX2_ENTRY_ATTR_CUSTOM_RANGE_END,

} sai_control_in_port_table_ex2_entry_attr_t;

/**
 * @brief Counter IDs in sai_get_example_stats() call
 */
typedef enum _sai_example_stat_t
{
    SAI_EXAMPLE_STAT_CONTROL_IN_PORT_TABLE_EX1_HIT_PACKETS,
    SAI_EXAMPLE_STAT_CONTROL_IN_PORT_TABLE_EX1_HIT_OCTETS,
    SAI_EXAMPLE_STAT_CONTROL_IN_PORT_TABLE_EX2_HIT_PACKETS,
    SAI_EXAMPLE_STAT_CONTROL_IN_PORT_TABLE_EX2_HIT_OCTETS,
} sai_example_stat_t;
/**
 * @brief Create control_in_port_table_ex1_entry
 *
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 * @param[out] entry_id Entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_create_control_in_port_table_ex1_entry_fn)(
        _Out_ sai_object_id_t *entry_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove control_in_port_table_ex1_entry
 *
 * @param[in] entry_id Entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_remove_control_in_port_table_ex1_entry_fn)(
        _In_ sai_object_id_t entry_id);

/**
 * @brief Set attribute for control_in_port_table_ex1_entry
 *
 * @param[in] entry_id Entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_set_control_in_port_table_ex1_entry_attribute_fn)(
        _In_ sai_object_id_t entry_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for control_in_port_table_ex1_entry
 *
 * @param[in] entry_id Entry id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_get_control_in_port_table_ex1_entry_attribute_fn)(
        _In_ sai_object_id_t entry_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create control_in_port_table_ex2_entry
 *
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 * @param[out] entry_id Entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_create_control_in_port_table_ex2_entry_fn)(
        _Out_ sai_object_id_t *entry_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove control_in_port_table_ex2_entry
 *
 * @param[in] entry_id Entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_remove_control_in_port_table_ex2_entry_fn)(
        _In_ sai_object_id_t entry_id);

/**
 * @brief Set attribute for control_in_port_table_ex2_entry
 *
 * @param[in] entry_id Entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_set_control_in_port_table_ex2_entry_attribute_fn)(
        _In_ sai_object_id_t entry_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for control_in_port_table_ex2_entry
 *
 * @param[in] entry_id Entry id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_get_control_in_port_table_ex2_entry_attribute_fn)(
        _In_ sai_object_id_t entry_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Get statistics counters.
 *
 * @param[in] entry_id Entry id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_get_example_stats_fn)(
        _In_ sai_object_id_t entry_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_example_stat_t *counter_ids,
        _Out_ uint64_t *counters);

/**
 * @brief Clear statistics counters.
 *
 * @param[in] entry_id Entry id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_clear_example_stats_fn)(
        _In_ sai_object_id_t entry_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_example_stat_t *counter_ids);

typedef struct _sai_example_api_t
{
    sai_create_control_in_port_table_ex1_entry_fn            create_control_in_port_table_ex1_entry;
    sai_remove_control_in_port_table_ex1_entry_fn            remove_control_in_port_table_ex1_entry;
    sai_set_control_in_port_table_ex1_entry_attribute_fn    set_control_in_port_table_ex1_entry_attribute;
    sai_get_control_in_port_table_ex1_entry_attribute_fn    get_control_in_port_table_ex1_entry_attribute;
    sai_create_control_in_port_table_ex2_entry_fn            create_control_in_port_table_ex2_entry;
    sai_remove_control_in_port_table_ex2_entry_fn            remove_control_in_port_table_ex2_entry;
    sai_set_control_in_port_table_ex2_entry_attribute_fn    set_control_in_port_table_ex2_entry_attribute;
    sai_get_control_in_port_table_ex2_entry_attribute_fn    get_control_in_port_table_ex2_entry_attribute;
    sai_get_example_stats_fn    get_example_stats;
    sai_clear_example_stats_fn    clear_example_stats;
} sai_example_api_t;
/**
 * @}
 */
#endif /** __SAIEXAMPLE_H_ */