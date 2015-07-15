module (((module_name))) where

import Data.Int
import Data.Text
import Data.Word

((* for m in msgs *))
((*- if m.static *))
((*- if m.sbp_id *))
(((m.identifier|to_global))) :: Word16
(((m.identifier|to_global))) = ((('0x%04X'|format(m.sbp_id))))
((*- endif *))
data (((m.identifier|to_data))) = (((m.identifier|to_data)))
((*- if not m.fields *))
  deriving ( Show, Read, Eq )
((*- endif *))
((*- for f in m.fields *))
((*- if loop.first *))
  { (((((m.identifier|to_global)+(f.identifier|camel_case)).ljust(m|max_fid_len)))) :: (((f|to_type)))
((*- else *))
  , (((((m.identifier|to_global)+(f.identifier|camel_case)).ljust(m|max_fid_len)))) :: (((f|to_type)))
((*- endif *))
((*- if loop.last *))
  } deriving ( Show, Read, Eq )
((*- endif *))
((*- endfor *))
((*- endif *))
((* endfor *))
