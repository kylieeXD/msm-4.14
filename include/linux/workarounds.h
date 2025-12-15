/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _XIMI_WORKAROUNDS_H
#define _XIMI_WORKAROUNDS_H

#include <linux/jump_label.h>
bool is_legacy_timestamp(void);

/* Fast-path helper for legacy timestamp selection */
extern struct static_key_false legacy_timestamp_key;
static inline bool is_legacy_timestamp_fast(void) {
	return static_branch_unlikely(&legacy_timestamp_key);
}

#endif /* _XIMI_WORKAROUNDS_H */
