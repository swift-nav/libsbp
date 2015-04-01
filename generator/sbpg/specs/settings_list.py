#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Dennis Zollo <dzollo@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""

"""

import yaml
import pprint


class SettingsList(object):
  """
  """

  list_of_dicts = list()

  def __init__(self, path_to_file):
    stream = open(path_to_file, "r")
    self.list_of_dicts = yaml.load(stream)
    print "Loaded settings yaml file from path " + path_to_file
    print "Number of settings loaded {0}".format(len(self.list_of_dicts))

  def __str__(self):
    pp = pprint.PrettyPrinter(indent=2)
    pp.pprint(self.list_of_dicts)

  def get_dict(self, group, name):
    for element in self.list_of_dicts:
      if element['name'] == name and element['group'] == group:
        return element

  def get_field(self, group, name, field):
    thisdict = self.get_dict(group, name)
    returnvar = ""
    if thisdict and isinstance(thisdict, dict):
      returnvar = thisdict.get(field, "")
    else:
      print "Error in settings list parsed yaml file."
      print "No entry for name {0} and group is {1}".format(name, group)
    if not returnvar:
      returnvar = ""
    return returnvar

  def return_groups(self):
    group_set = set()
    output = []
    for element in self.list_of_dicts:
      group = element['group']
      if group not in group_set:
        output.append(element['group'])
        group_set.add(group)
    return output
