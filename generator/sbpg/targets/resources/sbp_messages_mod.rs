// Copyright (C) 2015-2018 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

((*- for m in mods *))
pub mod (((m)));
((*- endfor *))

((*- for p in packages *))
((*- for m in p.definitions *))
((*- if m.sbp_id *))
use self::(((p.identifier|mod_name)))::(((m.identifier|camel_case)));
((*- endif *))
((*- endfor *))
((*- endfor *))

#[derive(Debug)]
pub enum SBP {
    Unknown { id: u16 },
    ((*- for m in msgs *))
    (((m.identifier|camel_case)))( (((m.identifier|camel_case))) ),
    ((*- endfor *))
}

impl SBP {
    pub fn parse(id: u16, payload: &mut &[u8]) -> SBP {
        match id {
            ((*- for m in msgs *))
            (((m.sbp_id))) => SBP::(((m.identifier|camel_case)))( (((m.identifier|camel_case)))::parse(payload) ),
            ((*- endfor *))
            _ => SBP::Unknown {id}
        }
    }
}
