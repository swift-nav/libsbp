{-# OPTIONS_GHC -fno-warn-unused-imports #-}
-- |
-- Module:      (((module_name)))
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- (((description | replace("\n", " ") | wordwrap(width=76, wrapstring="\n-- "))))

module (((module_name))) where

import BasicPrelude
import Control.Lens
import Control.Monad.Loops
import Data.Aeson.TH           (defaultOptions, deriveJSON, fieldLabelModifier)
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy    hiding (ByteString)
import Data.Int
import Data.Word
import SwiftNav.SBP.Encoding
import SwiftNav.SBP.TH
((*- for m in module_includes *))
import (((m)))
((*- endfor *))
((* for m in msgs *))
((*- if m.static *))
((*- if m.sbp_id *))
(((m.identifier|to_global))) :: Word16
(((m.identifier|to_global))) = ((('0x%04X'|format(m.sbp_id))))
((* endif *))
((*- if m.desc *))
((*- if not m.sbp_id *))
-- | (((m.identifier))).
((*- else *))
-- | SBP class for message (((m.identifier))) ((('(0x%04X)'|format(m.sbp_id)))).
((*- endif *))
--
-- (((m.desc | replace("\n", " ") | wordwrap(width=76, wrapstring="\n-- "))))
((*- endif *))
data (((m.identifier|to_data))) = (((m.identifier|to_data)))
((*- if not m.fields *))
  deriving ( Show, Read, Eq )
((*- endif *))
((*- for f in m.fields *))
((*- if loop.first *))
  { (((("_"+(m.identifier|to_global)+"_"+(f.identifier)).ljust(m|max_fid_len)))) :: (((f|to_type)))
    ((*- if f.desc *))
    -- ^ (((f.desc | replace("\n", " ") | wordwrap(width=72, wrapstring="\n    -- "))))
    ((*- endif *))
((*- else *))
  , (((("_"+(m.identifier|to_global)+"_"+(f.identifier)).ljust(m|max_fid_len)))) :: (((f|to_type)))
    ((*- if f.desc *))
    -- ^ (((f.desc | replace("\n", " ") | wordwrap(width=72, wrapstring="\n    -- "))))
    ((*- endif *))
((*- endif *))
((*- if loop.last *))
  } deriving ( Show, Read, Eq )
((*- endif *))
((*- endfor *))

instance Binary (((m.identifier|to_data))) where
((*- if not m.fields *))
  get =
    return (((m.identifier|to_data)))

  put (((m.identifier|to_data))) =
    return ()
((*- else *))
  get = do
((*- for f in m.fields *))
    ((("_"+(m.identifier|to_global)+"_"+(f.identifier)))) <- (((f|to_get)))
((*- endfor *))
    return (((m.identifier|to_data))) {..}

  put (((m.identifier|to_data))) {..} = do
((*- for f in m.fields *))
    (((f|to_put))) ((("_"+(m.identifier|to_global)+"_"+(f.identifier))))
((*- endfor *))
((*- endif *))

((*- if m.sbp_id *))

$(deriveSBP '(((m.identifier|to_global))) ''(((m.identifier|to_data))))
((* endif *))
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_(((m.identifier|to_global)))_" . stripPrefix "_(((m.identifier|to_global)))_"}
             ''(((m.identifier|to_data))))
$(makeLenses ''(((m.identifier|to_data))))

((*- endif *))
((* endfor *))
