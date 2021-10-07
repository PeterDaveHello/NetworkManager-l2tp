/* SPDX-License-Identifier: LGPL-2.1-or-later */
/* NetworkManager -- Network link manager
 *
 * (C) Copyright 2015 Red Hat, Inc.
 */

#ifndef __NM_DEFAULT_H__
#define __NM_DEFAULT_H__

/* makefiles define NETWORKMANAGER_COMPILATION for compiling NetworkManager.
 * Depending on which parts are compiled, different values are set. */
#define NM_NETWORKMANAGER_COMPILATION_DEFAULT    0x0001
#define NM_NETWORKMANAGER_COMPILATION_LIB_BASE   0x0002
#define NM_NETWORKMANAGER_COMPILATION_LIB_EDITOR 0x0004
#define NM_NETWORKMANAGER_COMPILATION_LIB        (0x0002 | 0x0004)

/* special flag, to indicate that we build a legacy library. That is, we link against
 * deprecated libnm-util/libnm-glib instead against libnm. */
#define NM_NETWORKMANAGER_COMPILATION_WITH_LIBNM_UTIL 0x0010

/*****************************************************************************/

#ifndef ___CONFIG_H__
#define ___CONFIG_H__
#include <config.h>
#endif

/* always include these headers for our internal source files. */

#include "nm-utils/nm-macros-internal.h"

#include "nm-version.h"
#include "nm-service-defines.h"

/*****************************************************************************/

#if ((NETWORKMANAGER_COMPILATION) &NM_NETWORKMANAGER_COMPILATION_LIB)

#include <glib/gi18n-lib.h>

#else

#include <glib/gi18n.h>

#endif /* NM_NETWORKMANAGER_COMPILATION_LIB */

/*****************************************************************************/

#if ((NETWORKMANAGER_COMPILATION) &NM_NETWORKMANAGER_COMPILATION_WITH_LIBNM_UTIL)

#define NM_VPN_LIBNM_COMPAT
#include <nm-connection.h>
#include <nm-setting-connection.h>
#include <nm-setting-8021x.h>
#include <nm-setting-ip4-config.h>
#include <nm-setting-vpn.h>
#include <nm-vpn-plugin-ui-interface.h>

#define nm_simple_connection_new nm_connection_new
#define NMSettingIPConfig        NMSettingIP4Config
#define NMIPRoute                NMIP4Route

#define NM_SETTING_IP_CONFIG                    NM_SETTING_IP4_CONFIG
#define NM_SETTING_IP_CONFIG_DHCP_SEND_HOSTNAME NM_SETTING_IP4_CONFIG_DHCP_SEND_HOSTNAME
#define NM_SETTING_IP_CONFIG_DNS                NM_SETTING_IP4_CONFIG_DNS
#define NM_SETTING_IP_CONFIG_DNS_SEARCH         NM_SETTING_IP4_CONFIG_DNS_SEARCH
#define NM_SETTING_IP_CONFIG_IGNORE_AUTO_DNS    NM_SETTING_IP4_CONFIG_IGNORE_AUTO_DNS
#define NM_SETTING_IP_CONFIG_IGNORE_AUTO_ROUTES NM_SETTING_IP4_CONFIG_IGNORE_AUTO_ROUTES
#define NM_SETTING_IP_CONFIG_METHOD             NM_SETTING_IP4_CONFIG_METHOD
#define NM_SETTING_IP_CONFIG_NEVER_DEFAULT      NM_SETTING_IP4_CONFIG_NEVER_DEFAULT
#define NM_SETTING_IP_CONFIG_ROUTES             NM_SETTING_IP4_CONFIG_ROUTES

#define NMV_EDITOR_PLUGIN_ERROR                   NM_SETTING_VPN_ERROR
#define NMV_EDITOR_PLUGIN_ERROR_FAILED            NM_SETTING_VPN_ERROR_UNKNOWN
#define NMV_EDITOR_PLUGIN_ERROR_INVALID_PROPERTY  NM_SETTING_VPN_ERROR_INVALID_PROPERTY
#define NMV_EDITOR_PLUGIN_ERROR_MISSING_PROPERTY  NM_SETTING_VPN_ERROR_MISSING_PROPERTY
#define NMV_EDITOR_PLUGIN_ERROR_FILE_NOT_VPN      NM_SETTING_VPN_ERROR_UNKNOWN
#define NMV_EDITOR_PLUGIN_ERROR_FILE_NOT_READABLE NM_SETTING_VPN_ERROR_UNKNOWN

#else /* !NM_NETWORKMANAGER_COMPILATION_WITH_LIBNM_UTIL */

#include <NetworkManager.h>

#define NMV_EDITOR_PLUGIN_ERROR                   NM_CONNECTION_ERROR
#define NMV_EDITOR_PLUGIN_ERROR_FAILED            NM_CONNECTION_ERROR_FAILED
#define NMV_EDITOR_PLUGIN_ERROR_INVALID_PROPERTY  NM_CONNECTION_ERROR_INVALID_PROPERTY
#define NMV_EDITOR_PLUGIN_ERROR_MISSING_PROPERTY  NM_CONNECTION_ERROR_MISSING_PROPERTY
#define NMV_EDITOR_PLUGIN_ERROR_FILE_NOT_VPN      NM_CONNECTION_ERROR_FAILED
#define NMV_EDITOR_PLUGIN_ERROR_FILE_NOT_READABLE NM_CONNECTION_ERROR_FAILED

#endif /* NM_NETWORKMANAGER_COMPILATION_WITH_LIBNM_UTIL */

/*****************************************************************************/

#if (NETWORKMANAGER_COMPILATION) & NM_NETWORKMANAGER_COMPILATION_LIB_EDITOR

#if ((NETWORKMANAGER_COMPILATION) &NM_NETWORKMANAGER_COMPILATION_WITH_LIBNM_UTIL)
#include <nm-ui-utils.h>
#else
#include <nma-ui-utils.h>
#endif

#endif /* NM_NETWORKMANAGER_COMPILATION_LIB_EDITOR */

/*****************************************************************************/

#endif /* __NM_DEFAULT_H__ */
