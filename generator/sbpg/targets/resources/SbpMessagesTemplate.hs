{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      (((module_name)))
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- (((description | comment_links | replace("\n", " ") | wordwrap(width=76, wrapstring="\n-- " ))))

module (((module_name)))
  ( module (((module_name)))
  ) where

import BasicPrelude
import Control.Lens
import Control.Monad.Loops
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString.Lazy    hiding (ByteString)
import Data.Int
import Data.Word
import SwiftNav.SBP.TH
((*- for m in module_includes *))
import (((m)))
((*- endfor *))

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}

((* for m in msgs *))
((*- if m.static *))
((*- if m.sbp_id *))
(((m.identifier|hs_to_global))) :: Word16
(((m.identifier|hs_to_global))) = ((('0x%04X'|format(m.sbp_id))))
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
data (((m.identifier|hs_to_data))) = (((m.identifier|hs_to_data)))
((*- if not m.fields *))
  deriving ( Show, Read, Eq )
((*- endif *))
((*- for f in m.fields *))
((*- if loop.first *))
  { (((("_"+(m.identifier|hs_to_global)+"_"+(f.identifier)).ljust(m|hs_max_fid_len)))) :: !(((f|hs_to_type)))
    ((*- if f.desc *))
    -- ^ (((f.desc | replace("\n", " ") | wordwrap(width=72, wrapstring="\n    -- "))))
    ((*- endif *))
((*- else *))
  , (((("_"+(m.identifier|hs_to_global)+"_"+(f.identifier)).ljust(m|hs_max_fid_len)))) :: !(((f|hs_to_type)))
    ((*- if f.desc *))
    -- ^ (((f.desc | replace("\n", " ") | wordwrap(width=72, wrapstring="\n    -- "))))
    ((*- endif *))
((*- endif *))
((*- if loop.last *))
  } deriving ( Show, Read, Eq )
((*- endif *))
((*- endfor *))

instance Binary (((m.identifier|hs_to_data))) where
((*- if not m.fields *))
  get =
    pure (((m.identifier|hs_to_data)))

  put (((m.identifier|hs_to_data))) =
    pure ()
((*- else *))
  get = do
((*- for f in m.fields *))
    ((("_"+(m.identifier|hs_to_global)+"_"+(f.identifier)))) <- (((f|hs_to_get)))
((*- endfor *))
    pure (((m.identifier|hs_to_data))) {..}

  put (((m.identifier|hs_to_data))) {..} = do
((*- for f in m.fields *))
    (((f|hs_to_put))) ((("_"+(m.identifier|hs_to_global)+"_"+(f.identifier))))
((*- endfor *))
((* endif *))

((*- if m.sbp_id *))
$(makeSBP '(((m.identifier|hs_to_global))) ''(((m.identifier|hs_to_data))))
((*- endif *))
$(makeJSON "_(((m.identifier|hs_to_global)))_" ''(((m.identifier|hs_to_data))))
$(makeLenses ''(((m.identifier|hs_to_data))))

((*- endif *))
((* endfor *))
