<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>install.dox</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/docs/</path>
    <filename>install_8dox</filename>
  </compound>
  <compound kind="file">
    <name>main.dox</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/docs/</path>
    <filename>main_8dox</filename>
  </compound>
  <compound kind="file">
    <name>acquisition.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>acquisition_8h</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">common.h</includes>
    <class kind="struct">msg_acq_result_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_ACQ_RESULT</name>
      <anchorfile>group__acquisition.html</anchorfile>
      <anchor>ga30f4c2660bdcd8dca1c69d712a71dca9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>bootload.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>bootload_8h</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">common.h</includes>
    <class kind="struct">msg_bootloader_handshake_t</class>
    <class kind="struct">msg_bootloader_jump_to_app_t</class>
    <class kind="struct">msg_nap_device_dna_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_BOOTLOADER_HANDSHAKE</name>
      <anchorfile>group__bootload.html</anchorfile>
      <anchor>gad1cab8ba36be6929d79dcc69ef84132d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_BOOTLOADER_JUMP_TO_APP</name>
      <anchorfile>group__bootload.html</anchorfile>
      <anchor>ga55bcdd971a9691e37e9ff3141351203a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_NAP_DEVICE_DNA</name>
      <anchorfile>group__bootload.html</anchorfile>
      <anchor>gaee3d85334bcfe0dfd4c1b5f4cd16e5c5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>common.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>common_8h</filename>
    <member kind="typedef">
      <type>int8_t</type>
      <name>s8</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>ga9e382f207c65ca13ab4ae98363aeda80</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int16_t</type>
      <name>s16</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>gaa980e2c02ba2305e0f489d5650655425</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32_t</type>
      <name>s32</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>gae9b1af5c037e57a98884758875d3a7c4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int64_t</type>
      <name>s64</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>ga350c6fc928e3bdc6c6486268ac8fb269</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint8_t</type>
      <name>u8</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>ga92c50087ca0e64fa93fc59402c55f8ca</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint16_t</type>
      <name>u16</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>gace9d960e74685e2cd84b36132dbbf8aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint32_t</type>
      <name>u32</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>gafaa62991928fb9fb18ff0db62a040aba</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint64_t</type>
      <name>u64</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>ga3f7e2bcbb0b4c338f3c4f6c937cd4234</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>edc.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>edc_8h</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">common.h</includes>
    <member kind="function">
      <type>u16</type>
      <name>crc16_ccitt</name>
      <anchorfile>group__crc.html</anchorfile>
      <anchor>gacde7cc46c9abec51644b9ba951ba957c</anchor>
      <arglist>(const u8 *buf, u32 len, u16 crc)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ext_events.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>ext__events_8h</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">common.h</includes>
    <class kind="struct">msg_ext_event_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_EXT_EVENT</name>
      <anchorfile>group__ext__events.html</anchorfile>
      <anchor>ga4d767be3bfc9e85ed39e8578b309c095</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>file_io.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>file__io_8h</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">common.h</includes>
    <class kind="struct">msg_fileio_read_t</class>
    <class kind="struct">msg_fileio_read_dir_t</class>
    <class kind="struct">msg_fileio_remove_t</class>
    <class kind="struct">msg_fileio_write_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FILEIO_READ</name>
      <anchorfile>group__file__io.html</anchorfile>
      <anchor>ga50ad4498a9e25b31949a410a4b102782</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FILEIO_READ_DIR</name>
      <anchorfile>group__file__io.html</anchorfile>
      <anchor>gace8550487b92c9bdfe2f89ae75b34370</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FILEIO_REMOVE</name>
      <anchorfile>group__file__io.html</anchorfile>
      <anchor>ga63e1e7a1fc3f2a00ba2e492e499c7d7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FILEIO_WRITE</name>
      <anchorfile>group__file__io.html</anchorfile>
      <anchor>gab546e6cee2da856c057d86b1f684b7e9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>flash.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>flash_8h</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">common.h</includes>
    <class kind="struct">msg_flash_program_t</class>
    <class kind="struct">msg_flash_done_t</class>
    <class kind="struct">msg_flash_read_t</class>
    <class kind="struct">msg_flash_erase_t</class>
    <class kind="struct">msg_stm_flash_lock_sector_t</class>
    <class kind="struct">msg_stm_flash_unlock_sector_t</class>
    <class kind="struct">msg_stm_unique_id_t</class>
    <class kind="struct">msg_m25_flash_write_status_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FLASH_PROGRAM</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>gaecf85438325ca7bdbbeea93e2169615a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FLASH_DONE</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>ga75c2df866e4cc80408f2b9353af087fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FLASH_READ</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>ga962eab7956a71a1e219c20df985a3f4e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FLASH_ERASE</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>ga524c614e8b8112e456dddf3a58ef7842</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_STM_FLASH_LOCK_SECTOR</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>gaa8b86b7c05775e2d0f02b052c24a48e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_STM_FLASH_UNLOCK_SECTOR</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>ga9bd94f97e941ce6158d6cd3b37e879b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_STM_UNIQUE_ID</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>ga887365123a2dc2a948b75da0f5ed94ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_M25_FLASH_WRITE_STATUS</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>ga76b38d0a23317874830d0516e1b4dd0b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>logging.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>logging_8h</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">common.h</includes>
    <class kind="struct">msg_print_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_PRINT</name>
      <anchorfile>group__logging.html</anchorfile>
      <anchor>ga93d12513680ce3a6b976506e2aa9f30c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_DEBUG_VAR</name>
      <anchorfile>group__logging.html</anchorfile>
      <anchor>gaa193b7913f6c64ce0a8299d1d988e778</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>navigation.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>navigation_8h</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">common.h</includes>
    <class kind="struct">msg_gps_time_t</class>
    <class kind="struct">msg_dops_t</class>
    <class kind="struct">msg_pos_ecef_t</class>
    <class kind="struct">msg_pos_llh_t</class>
    <class kind="struct">msg_baseline_ecef_t</class>
    <class kind="struct">msg_baseline_ned_t</class>
    <class kind="struct">msg_vel_ecef_t</class>
    <class kind="struct">msg_vel_ned_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_GPS_TIME</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>ga574838c82efa0d96380658fb7bf087d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_DOPS</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>gab10dc3f6f528cb3832d4f8d68d56094a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_POS_ECEF</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>gaf32c61302bd4d2611a9a7214145a05b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_POS_LLH</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>ga8161ba3bd38f1e147c441c04e6ac6a47</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_BASELINE_ECEF</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>ga02cead2855631de486b2e4932370e385</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_BASELINE_NED</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>gadaf37558986b88289917a25bcdafdff9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_VEL_ECEF</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>ga9b0d62bd42bdb051b0ef30446f3fbb43</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_VEL_NED</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>ga81d47a0fff23d53f923cff4397bd615f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>observation.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>observation_8h</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">common.h</includes>
    <class kind="struct">obs_gps_time_t</class>
    <class kind="struct">carrier_phase_t</class>
    <class kind="struct">observation_header_t</class>
    <class kind="struct">packed_obs_content_t</class>
    <class kind="struct">msg_obs_t</class>
    <class kind="struct">msg_base_pos_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_OBS</name>
      <anchorfile>group__observation.html</anchorfile>
      <anchor>ga1ef83ee2a1ca478305c970e28b1a22a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_BASE_POS</name>
      <anchorfile>group__observation.html</anchorfile>
      <anchor>ga393c0e479aee4032e2dfaecea5274c0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>piksi.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>piksi_8h</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">common.h</includes>
    <class kind="struct">msg_reset_filters_t</class>
    <class kind="struct">msg_thread_state_t</class>
    <class kind="struct">uart_channel_t</class>
    <class kind="struct">latency_t</class>
    <class kind="struct">msg_uart_state_t</class>
    <class kind="struct">msg_iar_state_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_ALMANAC</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga7c136114cd9549e6a852175e6451b6cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_SET_TIME</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga4e38d93ad11018b1b2390a22c86cfc61</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_RESET</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga493e05c55ff8fca2a074cc1b190b8b9c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_CW_RESULTS</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga113418fce4d9899913160391fec2cc32</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_CW_START</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>gaffc75ec26c6cfc4dca0f91d72abe3f06</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_RESET_FILTERS</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga6767b6e5ce2a90732ad40e4e2b7623d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_INIT_BASE</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga3f8e8348c35d09d524816a37c0bf5afb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_THREAD_STATE</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga8434690c40a3b1e4ac2f6043dff7091e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_UART_STATE</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga4b44d69e5338c1895b76d380446f1235</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_IAR_STATE</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>gadb1cc4b70e59119819215208d1c3eadf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>sbp.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>sbp_8h</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">common.h</includes>
    <class kind="struct">sbp_msg_callbacks_node</class>
    <class kind="struct">sbp_state_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_OK</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gab1bfbe8241e7d61d1dcb70fdbc6f5298</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_OK_CALLBACK_EXECUTED</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga4413cd9bfd4381243c814ad16c378c92</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_OK_CALLBACK_UNDEFINED</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga5b31cea8a8193070f96a1a6dba858581</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_CALLBACK_ERROR</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gaeeedd7321786d9510dc9cf48a3e266bf</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_CRC_ERROR</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gaf59365a3b5495dffbe085efb604235b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_SEND_ERROR</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gab6dd3e7910da229b12648359d69fbe71</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_NULL_ERROR</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga71d1c929c19e62f8ed7ce015d5d38413</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>void(*</type>
      <name>sbp_msg_callback_t</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga196882c04c16639a4395a436065c6068</anchor>
      <arglist>)(u16 sender_id, u8 len, u8 msg[], void *context)</arglist>
    </member>
    <member kind="typedef">
      <type>struct sbp_msg_callbacks_node</type>
      <name>sbp_msg_callbacks_node_t</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga69dc672590b2d79ba11f98dbaa0b33bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>s8</type>
      <name>sbp_register_callback</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga166014b1150a21e4421ecf1575a409f5</anchor>
      <arglist>(sbp_state_t *s, u16 msg_type, sbp_msg_callback_t cb, void *context, sbp_msg_callbacks_node_t *node)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sbp_clear_callbacks</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga13d29e90d75e4cf2b589cab02364adf2</anchor>
      <arglist>(sbp_state_t *s)</arglist>
    </member>
    <member kind="function">
      <type>sbp_msg_callbacks_node_t *</type>
      <name>sbp_find_callback</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga7eab683829921c0b25b979970c2b7293</anchor>
      <arglist>(sbp_state_t *s, u16 msg_type)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sbp_state_init</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga973aa9691a5d5b04dddf4312637d9d53</anchor>
      <arglist>(sbp_state_t *s)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sbp_state_set_io_context</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga32004b9a1589b99a3066b9abeee09e7a</anchor>
      <arglist>(sbp_state_t *s, void *context)</arglist>
    </member>
    <member kind="function">
      <type>s8</type>
      <name>sbp_process</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga2e3947801d6a64382a7d7cafb09258ba</anchor>
      <arglist>(sbp_state_t *s, u32(*read)(u8 *buff, u32 n, void *context))</arglist>
    </member>
    <member kind="function">
      <type>s8</type>
      <name>sbp_send_message</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga358e73f0e2cbb8343b434956ba24390b</anchor>
      <arglist>(sbp_state_t *s, u16 msg_type, u16 sender_id, u8 len, u8 *payload, u32(*write)(u8 *buff, u32 n, void *context))</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>settings.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>settings_8h</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">common.h</includes>
    <class kind="struct">msg_settings_t</class>
    <class kind="struct">msg_settings_read_by_index_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_SETTINGS</name>
      <anchorfile>group__settings.html</anchorfile>
      <anchor>ga272bac7b29641673c4f456661f949554</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_SETTINGS_SAVE</name>
      <anchorfile>group__settings.html</anchorfile>
      <anchor>ga323b2bd9bd47442cf5977b6637c4e6fe</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_SETTINGS_READ_BY_INDEX</name>
      <anchorfile>group__settings.html</anchorfile>
      <anchor>gafb7b9a6b540727b7ac569c90e12eb43f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>system.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>system_8h</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">common.h</includes>
    <class kind="struct">msg_startup_t</class>
    <class kind="struct">msg_heartbeat_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_STARTUP</name>
      <anchorfile>group__system.html</anchorfile>
      <anchor>ga6809a69b00436f949b2ea66a27feebb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_HEARTBEAT</name>
      <anchorfile>group__system.html</anchorfile>
      <anchor>ga1d47eaed84d17111c1497e0a96aca5ec</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>tracking.h</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>tracking_8h</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">common.h</includes>
    <class kind="struct">tracking_channel_state_t</class>
    <class kind="struct">msg_tracking_state_t</class>
    <class kind="struct">msg_ephemeris_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_TRACKING_STATE</name>
      <anchorfile>group__tracking.html</anchorfile>
      <anchor>ga6735e7c95167331c9fa4341d6908c857</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_EPHEMERIS</name>
      <anchorfile>group__tracking.html</anchorfile>
      <anchor>ga1966f368776c886dcedc047325cd2076</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>edc.c</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/src/</path>
    <filename>edc_8c</filename>
    <includes id="edc_8h" name="edc.h" local="yes" imported="no">edc.h</includes>
    <member kind="function">
      <type>u16</type>
      <name>crc16_ccitt</name>
      <anchorfile>group__crc.html</anchorfile>
      <anchor>gacde7cc46c9abec51644b9ba951ba957c</anchor>
      <arglist>(const u8 *buf, u32 len, u16 crc)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>sbp.c</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/src/</path>
    <filename>sbp_8c</filename>
    <includes id="edc_8h" name="edc.h" local="yes" imported="no">edc.h</includes>
    <includes id="sbp_8h" name="sbp.h" local="yes" imported="no">sbp.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>SBP_PREAMBLE</name>
      <anchorfile>sbp_8c.html</anchorfile>
      <anchor>a0fce977e2313eaad8103102ddd07094e</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>s8</type>
      <name>sbp_register_callback</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga166014b1150a21e4421ecf1575a409f5</anchor>
      <arglist>(sbp_state_t *s, u16 msg_type, sbp_msg_callback_t cb, void *context, sbp_msg_callbacks_node_t *node)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sbp_clear_callbacks</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga13d29e90d75e4cf2b589cab02364adf2</anchor>
      <arglist>(sbp_state_t *s)</arglist>
    </member>
    <member kind="function">
      <type>sbp_msg_callbacks_node_t *</type>
      <name>sbp_find_callback</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga7eab683829921c0b25b979970c2b7293</anchor>
      <arglist>(sbp_state_t *s, u16 msg_type)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sbp_state_init</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga973aa9691a5d5b04dddf4312637d9d53</anchor>
      <arglist>(sbp_state_t *s)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sbp_state_set_io_context</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga32004b9a1589b99a3066b9abeee09e7a</anchor>
      <arglist>(sbp_state_t *s, void *context)</arglist>
    </member>
    <member kind="function">
      <type>s8</type>
      <name>sbp_process</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga2e3947801d6a64382a7d7cafb09258ba</anchor>
      <arglist>(sbp_state_t *s, u32(*read)(u8 *buff, u32 n, void *context))</arglist>
    </member>
    <member kind="function">
      <type>s8</type>
      <name>sbp_send_message</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga358e73f0e2cbb8343b434956ba24390b</anchor>
      <arglist>(sbp_state_t *s, u16 msg_type, u16 sender_id, u8 len, u8 *payload, u32(*write)(u8 *buff, u32 n, void *context))</arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>install</name>
    <title>Installation</title>
    <filename>install</filename>
    <docanchor file="install" title="Obtaining the source">obtaining_source</docanchor>
    <docanchor file="install" title="Building from source">building_source</docanchor>
    <docanchor file="install" title="Building the documentation">building_docs</docanchor>
    <docanchor file="install" title="Cross-compiling">cross_compile</docanchor>
  </compound>
  <compound kind="group">
    <name>edc</name>
    <title>Error Detection and Correction</title>
    <filename>group__edc.html</filename>
    <subgroup>crc</subgroup>
  </compound>
  <compound kind="group">
    <name>crc</name>
    <title>CRC</title>
    <filename>group__crc.html</filename>
    <member kind="function">
      <type>u16</type>
      <name>crc16_ccitt</name>
      <anchorfile>group__crc.html</anchorfile>
      <anchor>gacde7cc46c9abec51644b9ba951ba957c</anchor>
      <arglist>(const u8 *buf, u32 len, u16 crc)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>sbp</name>
    <title>SBP</title>
    <filename>group__sbp.html</filename>
    <class kind="struct">sbp_msg_callbacks_node</class>
    <class kind="struct">sbp_state_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_OK</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gab1bfbe8241e7d61d1dcb70fdbc6f5298</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_OK_CALLBACK_EXECUTED</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga4413cd9bfd4381243c814ad16c378c92</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_OK_CALLBACK_UNDEFINED</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga5b31cea8a8193070f96a1a6dba858581</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_CALLBACK_ERROR</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gaeeedd7321786d9510dc9cf48a3e266bf</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_CRC_ERROR</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gaf59365a3b5495dffbe085efb604235b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_SEND_ERROR</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gab6dd3e7910da229b12648359d69fbe71</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_NULL_ERROR</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga71d1c929c19e62f8ed7ce015d5d38413</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>void(*</type>
      <name>sbp_msg_callback_t</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga196882c04c16639a4395a436065c6068</anchor>
      <arglist>)(u16 sender_id, u8 len, u8 msg[], void *context)</arglist>
    </member>
    <member kind="typedef">
      <type>struct sbp_msg_callbacks_node</type>
      <name>sbp_msg_callbacks_node_t</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga69dc672590b2d79ba11f98dbaa0b33bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>WAITING</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gga06fc87d81c62e9abb8790b6e5713c55ba757971c0bc5a1972d5f1b1be2c0e2087</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>GET_TYPE</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gga06fc87d81c62e9abb8790b6e5713c55ba9d77c0f7e14e04b7ecc95a029f669d83</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>GET_SENDER</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gga06fc87d81c62e9abb8790b6e5713c55ba66e9db660e0b9a41a016ee9aa17f1c8e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>GET_LEN</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gga06fc87d81c62e9abb8790b6e5713c55ba965c0199bc105c4df58589bb6b228a83</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>GET_MSG</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gga06fc87d81c62e9abb8790b6e5713c55baaaf15d67df991987408d4e77f15ff9e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>GET_CRC</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gga06fc87d81c62e9abb8790b6e5713c55bab043f4d9680ee3c06b3c0f7371da131b</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>s8</type>
      <name>sbp_register_callback</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga166014b1150a21e4421ecf1575a409f5</anchor>
      <arglist>(sbp_state_t *s, u16 msg_type, sbp_msg_callback_t cb, void *context, sbp_msg_callbacks_node_t *node)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sbp_clear_callbacks</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga13d29e90d75e4cf2b589cab02364adf2</anchor>
      <arglist>(sbp_state_t *s)</arglist>
    </member>
    <member kind="function">
      <type>sbp_msg_callbacks_node_t *</type>
      <name>sbp_find_callback</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga7eab683829921c0b25b979970c2b7293</anchor>
      <arglist>(sbp_state_t *s, u16 msg_type)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sbp_state_init</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga973aa9691a5d5b04dddf4312637d9d53</anchor>
      <arglist>(sbp_state_t *s)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sbp_state_set_io_context</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga32004b9a1589b99a3066b9abeee09e7a</anchor>
      <arglist>(sbp_state_t *s, void *context)</arglist>
    </member>
    <member kind="function">
      <type>s8</type>
      <name>sbp_process</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga2e3947801d6a64382a7d7cafb09258ba</anchor>
      <arglist>(sbp_state_t *s, u32(*read)(u8 *buff, u32 n, void *context))</arglist>
    </member>
    <member kind="function">
      <type>s8</type>
      <name>sbp_send_message</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>ga358e73f0e2cbb8343b434956ba24390b</anchor>
      <arglist>(sbp_state_t *s, u16 msg_type, u16 sender_id, u8 len, u8 *payload, u32(*write)(u8 *buff, u32 n, void *context))</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>acquisition</name>
    <title>Acquisition</title>
    <filename>group__acquisition.html</filename>
    <class kind="struct">msg_acq_result_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_ACQ_RESULT</name>
      <anchorfile>group__acquisition.html</anchorfile>
      <anchor>ga30f4c2660bdcd8dca1c69d712a71dca9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>bootload</name>
    <title>Bootload</title>
    <filename>group__bootload.html</filename>
    <class kind="struct">msg_bootloader_handshake_t</class>
    <class kind="struct">msg_bootloader_jump_to_app_t</class>
    <class kind="struct">msg_nap_device_dna_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_BOOTLOADER_HANDSHAKE</name>
      <anchorfile>group__bootload.html</anchorfile>
      <anchor>gad1cab8ba36be6929d79dcc69ef84132d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_BOOTLOADER_JUMP_TO_APP</name>
      <anchorfile>group__bootload.html</anchorfile>
      <anchor>ga55bcdd971a9691e37e9ff3141351203a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_NAP_DEVICE_DNA</name>
      <anchorfile>group__bootload.html</anchorfile>
      <anchor>gaee3d85334bcfe0dfd4c1b5f4cd16e5c5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>common_inttypes</name>
    <title>Integer types</title>
    <filename>group__common__inttypes.html</filename>
    <member kind="typedef">
      <type>int8_t</type>
      <name>s8</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>ga9e382f207c65ca13ab4ae98363aeda80</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int16_t</type>
      <name>s16</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>gaa980e2c02ba2305e0f489d5650655425</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32_t</type>
      <name>s32</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>gae9b1af5c037e57a98884758875d3a7c4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int64_t</type>
      <name>s64</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>ga350c6fc928e3bdc6c6486268ac8fb269</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint8_t</type>
      <name>u8</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>ga92c50087ca0e64fa93fc59402c55f8ca</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint16_t</type>
      <name>u16</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>gace9d960e74685e2cd84b36132dbbf8aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint32_t</type>
      <name>u32</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>gafaa62991928fb9fb18ff0db62a040aba</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint64_t</type>
      <name>u64</name>
      <anchorfile>group__common__inttypes.html</anchorfile>
      <anchor>ga3f7e2bcbb0b4c338f3c4f6c937cd4234</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ext_events</name>
    <title>Ext_events</title>
    <filename>group__ext__events.html</filename>
    <class kind="struct">msg_ext_event_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_EXT_EVENT</name>
      <anchorfile>group__ext__events.html</anchorfile>
      <anchor>ga4d767be3bfc9e85ed39e8578b309c095</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>file_io</name>
    <title>File_io</title>
    <filename>group__file__io.html</filename>
    <class kind="struct">msg_fileio_read_t</class>
    <class kind="struct">msg_fileio_read_dir_t</class>
    <class kind="struct">msg_fileio_remove_t</class>
    <class kind="struct">msg_fileio_write_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FILEIO_READ</name>
      <anchorfile>group__file__io.html</anchorfile>
      <anchor>ga50ad4498a9e25b31949a410a4b102782</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FILEIO_READ_DIR</name>
      <anchorfile>group__file__io.html</anchorfile>
      <anchor>gace8550487b92c9bdfe2f89ae75b34370</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FILEIO_REMOVE</name>
      <anchorfile>group__file__io.html</anchorfile>
      <anchor>ga63e1e7a1fc3f2a00ba2e492e499c7d7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FILEIO_WRITE</name>
      <anchorfile>group__file__io.html</anchorfile>
      <anchor>gab546e6cee2da856c057d86b1f684b7e9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>flash</name>
    <title>Flash</title>
    <filename>group__flash.html</filename>
    <class kind="struct">msg_flash_program_t</class>
    <class kind="struct">msg_flash_done_t</class>
    <class kind="struct">msg_flash_read_t</class>
    <class kind="struct">msg_flash_erase_t</class>
    <class kind="struct">msg_stm_flash_lock_sector_t</class>
    <class kind="struct">msg_stm_flash_unlock_sector_t</class>
    <class kind="struct">msg_stm_unique_id_t</class>
    <class kind="struct">msg_m25_flash_write_status_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FLASH_PROGRAM</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>gaecf85438325ca7bdbbeea93e2169615a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FLASH_DONE</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>ga75c2df866e4cc80408f2b9353af087fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FLASH_READ</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>ga962eab7956a71a1e219c20df985a3f4e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_FLASH_ERASE</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>ga524c614e8b8112e456dddf3a58ef7842</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_STM_FLASH_LOCK_SECTOR</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>gaa8b86b7c05775e2d0f02b052c24a48e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_STM_FLASH_UNLOCK_SECTOR</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>ga9bd94f97e941ce6158d6cd3b37e879b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_STM_UNIQUE_ID</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>ga887365123a2dc2a948b75da0f5ed94ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_M25_FLASH_WRITE_STATUS</name>
      <anchorfile>group__flash.html</anchorfile>
      <anchor>ga76b38d0a23317874830d0516e1b4dd0b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>logging</name>
    <title>Logging</title>
    <filename>group__logging.html</filename>
    <class kind="struct">msg_print_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_PRINT</name>
      <anchorfile>group__logging.html</anchorfile>
      <anchor>ga93d12513680ce3a6b976506e2aa9f30c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_DEBUG_VAR</name>
      <anchorfile>group__logging.html</anchorfile>
      <anchor>gaa193b7913f6c64ce0a8299d1d988e778</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>navigation</name>
    <title>Navigation</title>
    <filename>group__navigation.html</filename>
    <class kind="struct">msg_gps_time_t</class>
    <class kind="struct">msg_dops_t</class>
    <class kind="struct">msg_pos_ecef_t</class>
    <class kind="struct">msg_pos_llh_t</class>
    <class kind="struct">msg_baseline_ecef_t</class>
    <class kind="struct">msg_baseline_ned_t</class>
    <class kind="struct">msg_vel_ecef_t</class>
    <class kind="struct">msg_vel_ned_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_GPS_TIME</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>ga574838c82efa0d96380658fb7bf087d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_DOPS</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>gab10dc3f6f528cb3832d4f8d68d56094a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_POS_ECEF</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>gaf32c61302bd4d2611a9a7214145a05b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_POS_LLH</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>ga8161ba3bd38f1e147c441c04e6ac6a47</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_BASELINE_ECEF</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>ga02cead2855631de486b2e4932370e385</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_BASELINE_NED</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>gadaf37558986b88289917a25bcdafdff9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_VEL_ECEF</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>ga9b0d62bd42bdb051b0ef30446f3fbb43</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_VEL_NED</name>
      <anchorfile>group__navigation.html</anchorfile>
      <anchor>ga81d47a0fff23d53f923cff4397bd615f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>observation</name>
    <title>Observation</title>
    <filename>group__observation.html</filename>
    <class kind="struct">obs_gps_time_t</class>
    <class kind="struct">carrier_phase_t</class>
    <class kind="struct">observation_header_t</class>
    <class kind="struct">packed_obs_content_t</class>
    <class kind="struct">msg_obs_t</class>
    <class kind="struct">msg_base_pos_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_OBS</name>
      <anchorfile>group__observation.html</anchorfile>
      <anchor>ga1ef83ee2a1ca478305c970e28b1a22a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_BASE_POS</name>
      <anchorfile>group__observation.html</anchorfile>
      <anchor>ga393c0e479aee4032e2dfaecea5274c0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>piksi</name>
    <title>Piksi</title>
    <filename>group__piksi.html</filename>
    <class kind="struct">msg_reset_filters_t</class>
    <class kind="struct">msg_thread_state_t</class>
    <class kind="struct">uart_channel_t</class>
    <class kind="struct">latency_t</class>
    <class kind="struct">msg_uart_state_t</class>
    <class kind="struct">msg_iar_state_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_ALMANAC</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga7c136114cd9549e6a852175e6451b6cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_SET_TIME</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga4e38d93ad11018b1b2390a22c86cfc61</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_RESET</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga493e05c55ff8fca2a074cc1b190b8b9c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_CW_RESULTS</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga113418fce4d9899913160391fec2cc32</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_CW_START</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>gaffc75ec26c6cfc4dca0f91d72abe3f06</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_RESET_FILTERS</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga6767b6e5ce2a90732ad40e4e2b7623d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_INIT_BASE</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga3f8e8348c35d09d524816a37c0bf5afb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_THREAD_STATE</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga8434690c40a3b1e4ac2f6043dff7091e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_UART_STATE</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>ga4b44d69e5338c1895b76d380446f1235</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_IAR_STATE</name>
      <anchorfile>group__piksi.html</anchorfile>
      <anchor>gadb1cc4b70e59119819215208d1c3eadf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>settings</name>
    <title>Settings</title>
    <filename>group__settings.html</filename>
    <class kind="struct">msg_settings_t</class>
    <class kind="struct">msg_settings_read_by_index_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_SETTINGS</name>
      <anchorfile>group__settings.html</anchorfile>
      <anchor>ga272bac7b29641673c4f456661f949554</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_SETTINGS_SAVE</name>
      <anchorfile>group__settings.html</anchorfile>
      <anchor>ga323b2bd9bd47442cf5977b6637c4e6fe</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_SETTINGS_READ_BY_INDEX</name>
      <anchorfile>group__settings.html</anchorfile>
      <anchor>gafb7b9a6b540727b7ac569c90e12eb43f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>system</name>
    <title>System</title>
    <filename>group__system.html</filename>
    <class kind="struct">msg_startup_t</class>
    <class kind="struct">msg_heartbeat_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_STARTUP</name>
      <anchorfile>group__system.html</anchorfile>
      <anchor>ga6809a69b00436f949b2ea66a27feebb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_HEARTBEAT</name>
      <anchorfile>group__system.html</anchorfile>
      <anchor>ga1d47eaed84d17111c1497e0a96aca5ec</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>tracking</name>
    <title>Tracking</title>
    <filename>group__tracking.html</filename>
    <class kind="struct">tracking_channel_state_t</class>
    <class kind="struct">msg_tracking_state_t</class>
    <class kind="struct">msg_ephemeris_t</class>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_TRACKING_STATE</name>
      <anchorfile>group__tracking.html</anchorfile>
      <anchor>ga6735e7c95167331c9fa4341d6908c857</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SBP_MSG_EPHEMERIS</name>
      <anchorfile>group__tracking.html</anchorfile>
      <anchor>ga1966f368776c886dcedc047325cd2076</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>io</name>
    <title>Input / Output</title>
    <filename>group__io.html</filename>
    <subgroup>sbp</subgroup>
  </compound>
  <compound kind="struct">
    <name>carrier_phase_t</name>
    <filename>structcarrier__phase__t.html</filename>
    <member kind="variable">
      <type>s32</type>
      <name>i</name>
      <anchorfile>structcarrier__phase__t.html</anchorfile>
      <anchor>a7ec87d74df43b901c45d11e475d78a60</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>f</name>
      <anchorfile>structcarrier__phase__t.html</anchorfile>
      <anchor>a53325e9cd3d483310ad0ba8384682699</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>latency_t</name>
    <filename>structlatency__t.html</filename>
    <member kind="variable">
      <type>s32</type>
      <name>avg</name>
      <anchorfile>structlatency__t.html</anchorfile>
      <anchor>ae51a268e42cfdbe124c2446f49cf421d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>lmin</name>
      <anchorfile>structlatency__t.html</anchorfile>
      <anchor>a292c20f29be7a3973eb3caa7128ae577</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>lmax</name>
      <anchorfile>structlatency__t.html</anchorfile>
      <anchor>a57f29d673aa2a0fc8f614e12b3c5cf77</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>current</name>
      <anchorfile>structlatency__t.html</anchorfile>
      <anchor>a2bd186e5da49b0629560e710e8e3fa04</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_acq_result_t</name>
    <filename>structmsg__acq__result__t.html</filename>
    <member kind="variable">
      <type>float</type>
      <name>snr</name>
      <anchorfile>structmsg__acq__result__t.html</anchorfile>
      <anchor>a2f13c0d577ea505db647b3e3a8600831</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>float</type>
      <name>cp</name>
      <anchorfile>structmsg__acq__result__t.html</anchorfile>
      <anchor>a9d93de0395557b5d8f48bf41cbddeafa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>float</type>
      <name>cf</name>
      <anchorfile>structmsg__acq__result__t.html</anchorfile>
      <anchor>ac36447e13a2f0bd525c0eeb248b934ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>prn</name>
      <anchorfile>structmsg__acq__result__t.html</anchorfile>
      <anchor>abde7c1401d199d7a8657b81b57813df4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_base_pos_t</name>
    <filename>structmsg__base__pos__t.html</filename>
    <member kind="variable">
      <type>double</type>
      <name>lat</name>
      <anchorfile>structmsg__base__pos__t.html</anchorfile>
      <anchor>a7972334534f68166121a6e51b0aac2d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>lon</name>
      <anchorfile>structmsg__base__pos__t.html</anchorfile>
      <anchor>aa96391e04b5977c50b96d77bea86a01d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>height</name>
      <anchorfile>structmsg__base__pos__t.html</anchorfile>
      <anchor>a89f6abd564014faeff7cd20c340a9c7d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_baseline_ecef_t</name>
    <filename>structmsg__baseline__ecef__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>tow</name>
      <anchorfile>structmsg__baseline__ecef__t.html</anchorfile>
      <anchor>afd83f6a66dfc2964e1a24043b320974f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>x</name>
      <anchorfile>structmsg__baseline__ecef__t.html</anchorfile>
      <anchor>a9871e2f74b52ff0821e50c8f96903707</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>y</name>
      <anchorfile>structmsg__baseline__ecef__t.html</anchorfile>
      <anchor>a9df1916ec9b9ae5a3c1104844c09b965</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>z</name>
      <anchorfile>structmsg__baseline__ecef__t.html</anchorfile>
      <anchor>ac75f7017b1249d4fa94f2caf71459ef5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>accuracy</name>
      <anchorfile>structmsg__baseline__ecef__t.html</anchorfile>
      <anchor>a2da1ddd250415c13a908194ab2550a2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>n_sats</name>
      <anchorfile>structmsg__baseline__ecef__t.html</anchorfile>
      <anchor>acf91f57df88b5089fa02e70bb69cad8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>flags</name>
      <anchorfile>structmsg__baseline__ecef__t.html</anchorfile>
      <anchor>aa246fa433d167a7f6f8533227e40b76e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_baseline_ned_t</name>
    <filename>structmsg__baseline__ned__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>tow</name>
      <anchorfile>structmsg__baseline__ned__t.html</anchorfile>
      <anchor>afd83f6a66dfc2964e1a24043b320974f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>n</name>
      <anchorfile>structmsg__baseline__ned__t.html</anchorfile>
      <anchor>a556e26d96ce7e3210f7874f1d62c1442</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>e</name>
      <anchorfile>structmsg__baseline__ned__t.html</anchorfile>
      <anchor>a6318c44e5527992bb29244478be6ab1a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>d</name>
      <anchorfile>structmsg__baseline__ned__t.html</anchorfile>
      <anchor>abe9e578a0c450ec0bfb12e403b64d17b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>h_accuracy</name>
      <anchorfile>structmsg__baseline__ned__t.html</anchorfile>
      <anchor>a9cd7d28f5636fcad19d9a3c25c6cbf9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>v_accuracy</name>
      <anchorfile>structmsg__baseline__ned__t.html</anchorfile>
      <anchor>a5b0318351709f68a7333004e9e4992e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>n_sats</name>
      <anchorfile>structmsg__baseline__ned__t.html</anchorfile>
      <anchor>acf91f57df88b5089fa02e70bb69cad8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>flags</name>
      <anchorfile>structmsg__baseline__ned__t.html</anchorfile>
      <anchor>aa246fa433d167a7f6f8533227e40b76e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_bootloader_handshake_t</name>
    <filename>structmsg__bootloader__handshake__t.html</filename>
    <member kind="variable">
      <type>char</type>
      <name>handshake</name>
      <anchorfile>structmsg__bootloader__handshake__t.html</anchorfile>
      <anchor>aba1bf7bcc2fe6016cc9a507917ed0412</anchor>
      <arglist>[20]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_bootloader_jump_to_app_t</name>
    <filename>structmsg__bootloader__jump__to__app__t.html</filename>
    <member kind="variable">
      <type>u8</type>
      <name>jump</name>
      <anchorfile>structmsg__bootloader__jump__to__app__t.html</anchorfile>
      <anchor>a07dbb4656441a891c6e7bdaf4afcea60</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_dops_t</name>
    <filename>structmsg__dops__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>tow</name>
      <anchorfile>structmsg__dops__t.html</anchorfile>
      <anchor>afd83f6a66dfc2964e1a24043b320974f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>gdop</name>
      <anchorfile>structmsg__dops__t.html</anchorfile>
      <anchor>acb2537704ecdbd89b362ab90d669015e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>pdop</name>
      <anchorfile>structmsg__dops__t.html</anchorfile>
      <anchor>abaa192b3c43ab0872f403e71d63ce26a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>tdop</name>
      <anchorfile>structmsg__dops__t.html</anchorfile>
      <anchor>a402bb1d3f965fae3764659ba29cffef4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>hdop</name>
      <anchorfile>structmsg__dops__t.html</anchorfile>
      <anchor>acf41a0f579de34ff054f90e432cc2065</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>vdop</name>
      <anchorfile>structmsg__dops__t.html</anchorfile>
      <anchor>ad0386c924bc463bd54b2ba21de302747</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_ephemeris_t</name>
    <filename>structmsg__ephemeris__t.html</filename>
    <member kind="variable">
      <type>double</type>
      <name>tgd</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a1d5d087950aeab1c0cc8a441022bca0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>crs</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>aac8d746a5eea429e040380bea7c88dbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>crc</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a381bd89f3a55e8ecea923741e5023e3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>cuc</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>ab64511de94d7c7c8e19e82ee71a0054d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>cus</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>affaf938282722582b31db1949cfd1e22</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>cic</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>ab04216706bba32853fcc88f5c34149eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>cis</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a356b09cca99747a9cd84c3e59a49ad09</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>dn</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a4fd5a3c37897a5a3af1efd8dc98f52ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>m0</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a60cf4d542d78fd6e4771dfa7b7597ae1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>ecc</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a934ef9ffeec1c7d9c8a8c0656c1a7215</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>sqrta</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a1ce6a595846411eddb0c2afbdee7e3bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>omega0</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a787e3517035fd032aaa31caf97da3f89</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>omegadot</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a03dbb09fc9bb2a23665f2313c9de33ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>w</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>afb3248bab1c7ee0ad97e9d4c275b4c67</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>inc</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a165682680f21ca7ed5f2ded80212e5ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>inc_dot</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a1beb937a747ea1d04180daf7ad020fdd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>af0</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>ae858e620ccc58190580ffc5bf516b87b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>af1</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a4a09e6b75f86f0de93bf6b10558afa8a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>af2</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a559dae0c158dd684d0e6d2ffe2e11fce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>toe_tow</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a12387547b713aeabda4c36f583355939</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>toe_wn</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a28debe22dbbae034912e4cb0bb6dad3c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>toc_tow</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a5e5d8269e6034e7c49d758657d6a7dc1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>toc_wn</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>ac7e3edee1c6af3323afe3c65def9a39e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>valid</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a9f60101c9a3caa9a2dcde0b97e2cbcaa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>healthy</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>a483cb2a374d73b2dbdc894ca8802ad3d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>prn</name>
      <anchorfile>structmsg__ephemeris__t.html</anchorfile>
      <anchor>abde7c1401d199d7a8657b81b57813df4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_ext_event_t</name>
    <filename>structmsg__ext__event__t.html</filename>
    <member kind="variable">
      <type>u16</type>
      <name>wn</name>
      <anchorfile>structmsg__ext__event__t.html</anchorfile>
      <anchor>a59f61aa9e3c1bff3ad921187b203837d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u32</type>
      <name>tow</name>
      <anchorfile>structmsg__ext__event__t.html</anchorfile>
      <anchor>afd83f6a66dfc2964e1a24043b320974f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>ns</name>
      <anchorfile>structmsg__ext__event__t.html</anchorfile>
      <anchor>ab2243410c86c2d8c302c8ecf246dccc8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>flags</name>
      <anchorfile>structmsg__ext__event__t.html</anchorfile>
      <anchor>aa246fa433d167a7f6f8533227e40b76e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>pin</name>
      <anchorfile>structmsg__ext__event__t.html</anchorfile>
      <anchor>a41cd7366c3494d1a3fa3c9ab949a59a1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_fileio_read_dir_t</name>
    <filename>structmsg__fileio__read__dir__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>offset</name>
      <anchorfile>structmsg__fileio__read__dir__t.html</anchorfile>
      <anchor>a4ba37e6b40e12ce1d1e5dbee0323069d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>dirname</name>
      <anchorfile>structmsg__fileio__read__dir__t.html</anchorfile>
      <anchor>a370d8b92154d3184c41524301aa3a6a5</anchor>
      <arglist>[20]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_fileio_read_t</name>
    <filename>structmsg__fileio__read__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>offset</name>
      <anchorfile>structmsg__fileio__read__t.html</anchorfile>
      <anchor>a4ba37e6b40e12ce1d1e5dbee0323069d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>chunk_size</name>
      <anchorfile>structmsg__fileio__read__t.html</anchorfile>
      <anchor>ac786e84995b5249cf6147216eb24a4e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>filename</name>
      <anchorfile>structmsg__fileio__read__t.html</anchorfile>
      <anchor>adcdd8de726cde3547da221fceaf70391</anchor>
      <arglist>[20]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_fileio_remove_t</name>
    <filename>structmsg__fileio__remove__t.html</filename>
    <member kind="variable">
      <type>char</type>
      <name>filename</name>
      <anchorfile>structmsg__fileio__remove__t.html</anchorfile>
      <anchor>adcdd8de726cde3547da221fceaf70391</anchor>
      <arglist>[20]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_fileio_write_t</name>
    <filename>structmsg__fileio__write__t.html</filename>
    <member kind="variable">
      <type>char</type>
      <name>filename</name>
      <anchorfile>structmsg__fileio__write__t.html</anchorfile>
      <anchor>adcdd8de726cde3547da221fceaf70391</anchor>
      <arglist>[20]</arglist>
    </member>
    <member kind="variable">
      <type>u32</type>
      <name>offset</name>
      <anchorfile>structmsg__fileio__write__t.html</anchorfile>
      <anchor>a4ba37e6b40e12ce1d1e5dbee0323069d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>data</name>
      <anchorfile>structmsg__fileio__write__t.html</anchorfile>
      <anchor>a2873fa0c210cc63894b6cbb14e1a1330</anchor>
      <arglist>[0]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_flash_done_t</name>
    <filename>structmsg__flash__done__t.html</filename>
    <member kind="variable">
      <type>u8</type>
      <name>response</name>
      <anchorfile>structmsg__flash__done__t.html</anchorfile>
      <anchor>a5d616b8da5dd049a185840d30a848189</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_flash_erase_t</name>
    <filename>structmsg__flash__erase__t.html</filename>
    <member kind="variable">
      <type>u8</type>
      <name>target</name>
      <anchorfile>structmsg__flash__erase__t.html</anchorfile>
      <anchor>a6cd456c6c494c6164feefd0b7c1fc4e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u32</type>
      <name>sector_num</name>
      <anchorfile>structmsg__flash__erase__t.html</anchorfile>
      <anchor>abb04d753454ba34f0ca8eeb21c67dd1e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_flash_program_t</name>
    <filename>structmsg__flash__program__t.html</filename>
    <member kind="variable">
      <type>u8</type>
      <name>target</name>
      <anchorfile>structmsg__flash__program__t.html</anchorfile>
      <anchor>a6cd456c6c494c6164feefd0b7c1fc4e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>addr_start</name>
      <anchorfile>structmsg__flash__program__t.html</anchorfile>
      <anchor>aa2900af75ff2301341037fb65a7b71d7</anchor>
      <arglist>[3]</arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>addr_len</name>
      <anchorfile>structmsg__flash__program__t.html</anchorfile>
      <anchor>a79ae5c80b892c3be0499005fd09d635b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>data</name>
      <anchorfile>structmsg__flash__program__t.html</anchorfile>
      <anchor>a2873fa0c210cc63894b6cbb14e1a1330</anchor>
      <arglist>[0]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_flash_read_t</name>
    <filename>structmsg__flash__read__t.html</filename>
    <member kind="variable">
      <type>u8</type>
      <name>target</name>
      <anchorfile>structmsg__flash__read__t.html</anchorfile>
      <anchor>a6cd456c6c494c6164feefd0b7c1fc4e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>addr_start</name>
      <anchorfile>structmsg__flash__read__t.html</anchorfile>
      <anchor>aa2900af75ff2301341037fb65a7b71d7</anchor>
      <arglist>[3]</arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>addr_len</name>
      <anchorfile>structmsg__flash__read__t.html</anchorfile>
      <anchor>a79ae5c80b892c3be0499005fd09d635b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_gps_time_t</name>
    <filename>structmsg__gps__time__t.html</filename>
    <member kind="variable">
      <type>u16</type>
      <name>wn</name>
      <anchorfile>structmsg__gps__time__t.html</anchorfile>
      <anchor>a59f61aa9e3c1bff3ad921187b203837d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u32</type>
      <name>tow</name>
      <anchorfile>structmsg__gps__time__t.html</anchorfile>
      <anchor>afd83f6a66dfc2964e1a24043b320974f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>ns</name>
      <anchorfile>structmsg__gps__time__t.html</anchorfile>
      <anchor>ab2243410c86c2d8c302c8ecf246dccc8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>flags</name>
      <anchorfile>structmsg__gps__time__t.html</anchorfile>
      <anchor>aa246fa433d167a7f6f8533227e40b76e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_heartbeat_t</name>
    <filename>structmsg__heartbeat__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>flags</name>
      <anchorfile>structmsg__heartbeat__t.html</anchorfile>
      <anchor>a9fb2abd9f2594cefc48d6856e01f2879</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_iar_state_t</name>
    <filename>structmsg__iar__state__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>num_hyps</name>
      <anchorfile>structmsg__iar__state__t.html</anchorfile>
      <anchor>a71d4f38de2f594088eff5bdc08c8ee4c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_m25_flash_write_status_t</name>
    <filename>structmsg__m25__flash__write__status__t.html</filename>
    <member kind="variable">
      <type>u8</type>
      <name>status</name>
      <anchorfile>structmsg__m25__flash__write__status__t.html</anchorfile>
      <anchor>a0b815462138714153d77b864396b72bd</anchor>
      <arglist>[1]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_nap_device_dna_t</name>
    <filename>structmsg__nap__device__dna__t.html</filename>
    <member kind="variable">
      <type>u8</type>
      <name>dna</name>
      <anchorfile>structmsg__nap__device__dna__t.html</anchorfile>
      <anchor>a92c318cc19eafe8805c3dda915d5d322</anchor>
      <arglist>[8]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_obs_t</name>
    <filename>structmsg__obs__t.html</filename>
    <member kind="variable">
      <type>observation_header_t</type>
      <name>header</name>
      <anchorfile>structmsg__obs__t.html</anchorfile>
      <anchor>a7e1ea03c7a1e3350ca63057d9b212ec5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>packed_obs_content_t</type>
      <name>obs</name>
      <anchorfile>structmsg__obs__t.html</anchorfile>
      <anchor>a6d97b0183cbee920570b03b330e7e42d</anchor>
      <arglist>[0]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_pos_ecef_t</name>
    <filename>structmsg__pos__ecef__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>tow</name>
      <anchorfile>structmsg__pos__ecef__t.html</anchorfile>
      <anchor>afd83f6a66dfc2964e1a24043b320974f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>x</name>
      <anchorfile>structmsg__pos__ecef__t.html</anchorfile>
      <anchor>af88b946fb90d5f08b5fb740c70e98c10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>y</name>
      <anchorfile>structmsg__pos__ecef__t.html</anchorfile>
      <anchor>ab927965981178aa1fba979a37168db2a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>z</name>
      <anchorfile>structmsg__pos__ecef__t.html</anchorfile>
      <anchor>ab3e6ed577a7c669c19de1f9c1b46c872</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>accuracy</name>
      <anchorfile>structmsg__pos__ecef__t.html</anchorfile>
      <anchor>a2da1ddd250415c13a908194ab2550a2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>n_sats</name>
      <anchorfile>structmsg__pos__ecef__t.html</anchorfile>
      <anchor>acf91f57df88b5089fa02e70bb69cad8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>flags</name>
      <anchorfile>structmsg__pos__ecef__t.html</anchorfile>
      <anchor>aa246fa433d167a7f6f8533227e40b76e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_pos_llh_t</name>
    <filename>structmsg__pos__llh__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>tow</name>
      <anchorfile>structmsg__pos__llh__t.html</anchorfile>
      <anchor>afd83f6a66dfc2964e1a24043b320974f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>lat</name>
      <anchorfile>structmsg__pos__llh__t.html</anchorfile>
      <anchor>a7972334534f68166121a6e51b0aac2d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>lon</name>
      <anchorfile>structmsg__pos__llh__t.html</anchorfile>
      <anchor>aa96391e04b5977c50b96d77bea86a01d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>height</name>
      <anchorfile>structmsg__pos__llh__t.html</anchorfile>
      <anchor>a89f6abd564014faeff7cd20c340a9c7d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>h_accuracy</name>
      <anchorfile>structmsg__pos__llh__t.html</anchorfile>
      <anchor>a9cd7d28f5636fcad19d9a3c25c6cbf9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>v_accuracy</name>
      <anchorfile>structmsg__pos__llh__t.html</anchorfile>
      <anchor>a5b0318351709f68a7333004e9e4992e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>n_sats</name>
      <anchorfile>structmsg__pos__llh__t.html</anchorfile>
      <anchor>acf91f57df88b5089fa02e70bb69cad8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>flags</name>
      <anchorfile>structmsg__pos__llh__t.html</anchorfile>
      <anchor>aa246fa433d167a7f6f8533227e40b76e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_print_t</name>
    <filename>structmsg__print__t.html</filename>
    <member kind="variable">
      <type>char *</type>
      <name>text</name>
      <anchorfile>structmsg__print__t.html</anchorfile>
      <anchor>a5633b1433389cec21ade3811bbe9ca5b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_reset_filters_t</name>
    <filename>structmsg__reset__filters__t.html</filename>
    <member kind="variable">
      <type>u8</type>
      <name>filter</name>
      <anchorfile>structmsg__reset__filters__t.html</anchorfile>
      <anchor>a706503214a6d2954bc7b49af050315fe</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_settings_read_by_index_t</name>
    <filename>structmsg__settings__read__by__index__t.html</filename>
    <member kind="variable">
      <type>u16</type>
      <name>index</name>
      <anchorfile>structmsg__settings__read__by__index__t.html</anchorfile>
      <anchor>aceac89c5a3f513fbaf0d24a293ccb75c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_settings_t</name>
    <filename>structmsg__settings__t.html</filename>
    <member kind="variable">
      <type>char *</type>
      <name>setting</name>
      <anchorfile>structmsg__settings__t.html</anchorfile>
      <anchor>a17f469a7c8c353e987122ba53a6e7823</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_startup_t</name>
    <filename>structmsg__startup__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>reserved</name>
      <anchorfile>structmsg__startup__t.html</anchorfile>
      <anchor>ac429abb4d17158f1d4b8390ae6a1ee8f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_stm_flash_lock_sector_t</name>
    <filename>structmsg__stm__flash__lock__sector__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>sector</name>
      <anchorfile>structmsg__stm__flash__lock__sector__t.html</anchorfile>
      <anchor>a2fd226114f901251c2985bae9924cbf6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_stm_flash_unlock_sector_t</name>
    <filename>structmsg__stm__flash__unlock__sector__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>sector</name>
      <anchorfile>structmsg__stm__flash__unlock__sector__t.html</anchorfile>
      <anchor>a2fd226114f901251c2985bae9924cbf6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_stm_unique_id_t</name>
    <filename>structmsg__stm__unique__id__t.html</filename>
    <member kind="variable">
      <type>u8</type>
      <name>stm_id</name>
      <anchorfile>structmsg__stm__unique__id__t.html</anchorfile>
      <anchor>a179a186e49f95c96c275a9f2b85954f3</anchor>
      <arglist>[12]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_thread_state_t</name>
    <filename>structmsg__thread__state__t.html</filename>
    <member kind="variable">
      <type>char</type>
      <name>name</name>
      <anchorfile>structmsg__thread__state__t.html</anchorfile>
      <anchor>a9997d8ee2df51d18efed254a5aa016fd</anchor>
      <arglist>[20]</arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>cpu</name>
      <anchorfile>structmsg__thread__state__t.html</anchorfile>
      <anchor>abc481900d4d56f2be2964e769f928c31</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u32</type>
      <name>stack_free</name>
      <anchorfile>structmsg__thread__state__t.html</anchorfile>
      <anchor>aab15869955813e57adc7844d60471a77</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_tracking_state_t</name>
    <filename>structmsg__tracking__state__t.html</filename>
    <member kind="variable">
      <type>tracking_channel_state_t</type>
      <name>states</name>
      <anchorfile>structmsg__tracking__state__t.html</anchorfile>
      <anchor>ae826d3c584a78ec3a7dc6fd2d9214d9c</anchor>
      <arglist>[0]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_uart_state_t</name>
    <filename>structmsg__uart__state__t.html</filename>
    <member kind="variable">
      <type>uart_channel_t</type>
      <name>uart_a</name>
      <anchorfile>structmsg__uart__state__t.html</anchorfile>
      <anchor>a8dd56801272a9c8c33c48cfd6b02f693</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uart_channel_t</type>
      <name>uart_b</name>
      <anchorfile>structmsg__uart__state__t.html</anchorfile>
      <anchor>a52d86b276422415300ceaa6cb44c7462</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uart_channel_t</type>
      <name>uart_ftdi</name>
      <anchorfile>structmsg__uart__state__t.html</anchorfile>
      <anchor>a9283958c7d392f68d35cd73ae6c38a22</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>latency_t</type>
      <name>latency</name>
      <anchorfile>structmsg__uart__state__t.html</anchorfile>
      <anchor>a15f348f10190e66d43c73d87fbec5d89</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_vel_ecef_t</name>
    <filename>structmsg__vel__ecef__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>tow</name>
      <anchorfile>structmsg__vel__ecef__t.html</anchorfile>
      <anchor>afd83f6a66dfc2964e1a24043b320974f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>x</name>
      <anchorfile>structmsg__vel__ecef__t.html</anchorfile>
      <anchor>a9871e2f74b52ff0821e50c8f96903707</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>y</name>
      <anchorfile>structmsg__vel__ecef__t.html</anchorfile>
      <anchor>a9df1916ec9b9ae5a3c1104844c09b965</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>z</name>
      <anchorfile>structmsg__vel__ecef__t.html</anchorfile>
      <anchor>ac75f7017b1249d4fa94f2caf71459ef5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>accuracy</name>
      <anchorfile>structmsg__vel__ecef__t.html</anchorfile>
      <anchor>a2da1ddd250415c13a908194ab2550a2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>n_sats</name>
      <anchorfile>structmsg__vel__ecef__t.html</anchorfile>
      <anchor>acf91f57df88b5089fa02e70bb69cad8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>flags</name>
      <anchorfile>structmsg__vel__ecef__t.html</anchorfile>
      <anchor>aa246fa433d167a7f6f8533227e40b76e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>msg_vel_ned_t</name>
    <filename>structmsg__vel__ned__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>tow</name>
      <anchorfile>structmsg__vel__ned__t.html</anchorfile>
      <anchor>afd83f6a66dfc2964e1a24043b320974f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>n</name>
      <anchorfile>structmsg__vel__ned__t.html</anchorfile>
      <anchor>a556e26d96ce7e3210f7874f1d62c1442</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>e</name>
      <anchorfile>structmsg__vel__ned__t.html</anchorfile>
      <anchor>a6318c44e5527992bb29244478be6ab1a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>s32</type>
      <name>d</name>
      <anchorfile>structmsg__vel__ned__t.html</anchorfile>
      <anchor>abe9e578a0c450ec0bfb12e403b64d17b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>h_accuracy</name>
      <anchorfile>structmsg__vel__ned__t.html</anchorfile>
      <anchor>a9cd7d28f5636fcad19d9a3c25c6cbf9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>v_accuracy</name>
      <anchorfile>structmsg__vel__ned__t.html</anchorfile>
      <anchor>a5b0318351709f68a7333004e9e4992e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>n_sats</name>
      <anchorfile>structmsg__vel__ned__t.html</anchorfile>
      <anchor>acf91f57df88b5089fa02e70bb69cad8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>flags</name>
      <anchorfile>structmsg__vel__ned__t.html</anchorfile>
      <anchor>aa246fa433d167a7f6f8533227e40b76e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>obs_gps_time_t</name>
    <filename>structobs__gps__time__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>tow</name>
      <anchorfile>structobs__gps__time__t.html</anchorfile>
      <anchor>afd83f6a66dfc2964e1a24043b320974f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>wn</name>
      <anchorfile>structobs__gps__time__t.html</anchorfile>
      <anchor>a59f61aa9e3c1bff3ad921187b203837d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>observation_header_t</name>
    <filename>structobservation__header__t.html</filename>
    <member kind="variable">
      <type>obs_gps_time_t</type>
      <name>t</name>
      <anchorfile>structobservation__header__t.html</anchorfile>
      <anchor>a433d5282ed602469c948d863a0b5c38e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>n_obs</name>
      <anchorfile>structobservation__header__t.html</anchorfile>
      <anchor>a0f457df8cc656bf837073fa6fe3823af</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>packed_obs_content_t</name>
    <filename>structpacked__obs__content__t.html</filename>
    <member kind="variable">
      <type>u32</type>
      <name>P</name>
      <anchorfile>structpacked__obs__content__t.html</anchorfile>
      <anchor>afe2cfdf116f74799f3002b5f5cd39edd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>carrier_phase_t</type>
      <name>L</name>
      <anchorfile>structpacked__obs__content__t.html</anchorfile>
      <anchor>a14d771aca22bb730a648bb5c069fc36a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>cn0</name>
      <anchorfile>structpacked__obs__content__t.html</anchorfile>
      <anchor>aebf8f9082556156411ac8515999b9959</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>lock</name>
      <anchorfile>structpacked__obs__content__t.html</anchorfile>
      <anchor>aebb086e1f20427733693bc9998c9a8e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>prn</name>
      <anchorfile>structpacked__obs__content__t.html</anchorfile>
      <anchor>abde7c1401d199d7a8657b81b57813df4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>sbp_msg_callbacks_node</name>
    <filename>structsbp__msg__callbacks__node.html</filename>
    <member kind="variable">
      <type>u16</type>
      <name>msg_type</name>
      <anchorfile>structsbp__msg__callbacks__node.html</anchorfile>
      <anchor>a3aea35f8cfa31ada4f4843b95376d6dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>sbp_msg_callback_t</type>
      <name>cb</name>
      <anchorfile>structsbp__msg__callbacks__node.html</anchorfile>
      <anchor>aa76cf2df78a78d0005f8f71ab7dd2215</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>void *</type>
      <name>context</name>
      <anchorfile>structsbp__msg__callbacks__node.html</anchorfile>
      <anchor>ae376f130b17d169ee51be68077a89ed0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct sbp_msg_callbacks_node *</type>
      <name>next</name>
      <anchorfile>structsbp__msg__callbacks__node.html</anchorfile>
      <anchor>ad4f5ae7fa797f31b4071ff3054f4d055</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>sbp_state_t</name>
    <filename>structsbp__state__t.html</filename>
    <member kind="enumvalue">
      <type>@</type>
      <name>WAITING</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gga06fc87d81c62e9abb8790b6e5713c55ba757971c0bc5a1972d5f1b1be2c0e2087</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>GET_TYPE</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gga06fc87d81c62e9abb8790b6e5713c55ba9d77c0f7e14e04b7ecc95a029f669d83</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>GET_SENDER</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gga06fc87d81c62e9abb8790b6e5713c55ba66e9db660e0b9a41a016ee9aa17f1c8e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>GET_LEN</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gga06fc87d81c62e9abb8790b6e5713c55ba965c0199bc105c4df58589bb6b228a83</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>GET_MSG</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gga06fc87d81c62e9abb8790b6e5713c55baaaf15d67df991987408d4e77f15ff9e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>GET_CRC</name>
      <anchorfile>group__sbp.html</anchorfile>
      <anchor>gga06fc87d81c62e9abb8790b6e5713c55bab043f4d9680ee3c06b3c0f7371da131b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>enum sbp_state_t::@0</type>
      <name>state</name>
      <anchorfile>structsbp__state__t.html</anchorfile>
      <anchor>a401e908dfe3397a134e0b6a5fb9ef49f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>msg_type</name>
      <anchorfile>structsbp__state__t.html</anchorfile>
      <anchor>a3aea35f8cfa31ada4f4843b95376d6dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>sender_id</name>
      <anchorfile>structsbp__state__t.html</anchorfile>
      <anchor>a0cbfd514575db0c58c28820682201ef3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>crc</name>
      <anchorfile>structsbp__state__t.html</anchorfile>
      <anchor>ad584d87183b5f8733980d11d9cc8cb7a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>msg_len</name>
      <anchorfile>structsbp__state__t.html</anchorfile>
      <anchor>a56bbda72fa0bb2a2441f915594cb87ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>n_read</name>
      <anchorfile>structsbp__state__t.html</anchorfile>
      <anchor>a4a2e032e31054cd55db740553b8f4c70</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>msg_buff</name>
      <anchorfile>structsbp__state__t.html</anchorfile>
      <anchor>a94b635810b8de59eb70518c52445b9bd</anchor>
      <arglist>[256]</arglist>
    </member>
    <member kind="variable">
      <type>void *</type>
      <name>io_context</name>
      <anchorfile>structsbp__state__t.html</anchorfile>
      <anchor>ac5554d73848bb9e4a985aea187ec08a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>sbp_msg_callbacks_node_t *</type>
      <name>sbp_msg_callbacks_head</name>
      <anchorfile>structsbp__state__t.html</anchorfile>
      <anchor>a2b2568dd0296992c50a998a280800664</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>tracking_channel_state_t</name>
    <filename>structtracking__channel__state__t.html</filename>
    <member kind="variable">
      <type>u8</type>
      <name>state</name>
      <anchorfile>structtracking__channel__state__t.html</anchorfile>
      <anchor>ad0bc4e4e6e6ffc52d9079b73afd73887</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>prn</name>
      <anchorfile>structtracking__channel__state__t.html</anchorfile>
      <anchor>abde7c1401d199d7a8657b81b57813df4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>float</type>
      <name>cn0</name>
      <anchorfile>structtracking__channel__state__t.html</anchorfile>
      <anchor>a0ed0a3a518752a223493b44fe899a9fd</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>uart_channel_t</name>
    <filename>structuart__channel__t.html</filename>
    <member kind="variable">
      <type>float</type>
      <name>tx_throughput</name>
      <anchorfile>structuart__channel__t.html</anchorfile>
      <anchor>a213cd413e3d89d961980be0b804c918c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>float</type>
      <name>rx_throughput</name>
      <anchorfile>structuart__channel__t.html</anchorfile>
      <anchor>acfcf75b0dd6875d9e14718b83289137a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>crc_error_count</name>
      <anchorfile>structuart__channel__t.html</anchorfile>
      <anchor>a507d8e9ed16895f8f75a9a7d10ea30ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u16</type>
      <name>io_error_count</name>
      <anchorfile>structuart__channel__t.html</anchorfile>
      <anchor>a8642df4c0de6948016f985b93fdc0cbe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>tx_buffer_level</name>
      <anchorfile>structuart__channel__t.html</anchorfile>
      <anchor>a0df3542de85a61f197e2864a682c3bc3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>u8</type>
      <name>rx_buffer_level</name>
      <anchorfile>structuart__channel__t.html</anchorfile>
      <anchor>a7c21395c0e3cf1ae7dcfa475b41303de</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="dir">
    <name>include</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/</path>
    <filename>dir_d44c64559bbebec7f509842c48db8b23.html</filename>
    <dir>include/libsbp</dir>
  </compound>
  <compound kind="dir">
    <name>include/libsbp</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/include/libsbp/</path>
    <filename>dir_4f207b46e8207587823dc5b4e3917e6e.html</filename>
    <file>acquisition.h</file>
    <file>bootload.h</file>
    <file>common.h</file>
    <file>edc.h</file>
    <file>ext_events.h</file>
    <file>file_io.h</file>
    <file>flash.h</file>
    <file>logging.h</file>
    <file>navigation.h</file>
    <file>observation.h</file>
    <file>piksi.h</file>
    <file>sbp.h</file>
    <file>settings.h</file>
    <file>system.h</file>
    <file>tracking.h</file>
  </compound>
  <compound kind="dir">
    <name>src</name>
    <path>/Users/mookerji/Dropbox/Documents/swift/clones/libsbp/c/src/</path>
    <filename>dir_68267d1309a1af8e8297ef4c3efbcdba.html</filename>
    <file>edc.c</file>
    <file>sbp.c</file>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title></title>
    <filename>index</filename>
  </compound>
</tagfile>
