import sbp.observation
from sbp.msg import SBP
from sbp.table import dispatch, _SBP_TABLE
import base64
import json

json_str= """{"length":147,"preamble":85,"sender":50347,"msg_type":74,"obs":[{"L":{"f":67,"i":119765916},"flags":15,"cn0":197,"P":1139534880,"D":{"f":30,"i":-3223},"lock":14,"sid":{"sat":1,"code":0}},{"L":{"f":250,"i":107993151},"flags":15,"cn0":212,"P":1027520789,"D":{"f":69,"i":-1399},"lock":14,"sid":{"sat":3,"code":0}},{"L":{"f":72,"i":116282754},"flags":15,"cn0":208,"P":1106393755,"D":{"f":24,"i":3218},"lock":14,"sid":{"sat":9,"code":0}},{"L":{"f":216,"i":116153161},"flags":15,"cn0":193,"P":1105160778,"D":{"f":65,"i":-2317},"lock":14,"sid":{"sat":22,"code":0}},{"L":{"f":22,"i":111475114},"flags":15,"cn0":202,"P":1060650500,"D":{"f":196,"i":1583},"lock":14,"sid":{"sat":23,"code":0}},{"L":{"f":33,"i":110798348},"flags":15,"cn0":219,"P":1037812643,"D":{"f":55,"i":-3408},"lock":14,"sid":{"sat":22,"code":3}},{"L":{"f":220,"i":106341805},"flags":15,"cn0":124,"P":993276095,"D":{"f":84,"i":-2056},"lock":14,"sid":{"sat":7,"code":3}},{"L":{"f":16,"i":126877552},"flags":15,"cn0":160,"P":1218274499,"D":{"f":206,"i":-3328},"lock":14,"sid":{"sat":12,"code":12}}],"payload":"oPOqBwAAAADqBxAg7OtDnHsjB0Np8x7FDg8BABW5Pj0/2G8G+on6RdQODwMAmzryQYJV7gZIkgwY0A4PCQBKat9BSVvsBtjz9kHBDg8WAAQ+OD+q+aQGFi8GxMoODxcAo8PbPQymmgYhsPI32w4PFgO/MDQ7raVWBtz491R8Dg8HA8NknUhw/48HEADzzqAODwwM","header":{"n_obs":16,"t":{"ns_residual":0,"wn":2026,"tow":128644000}},"crc":4524}"""


def test_roundtrip_payload():
    obs_dict = json.loads(json_str)
    obs_json = sbp.observation.MsgObs.from_json(json_str)
    obs_binary = sbp.observation.MsgObs(SBP(obs_dict['msg_type'], obs_dict['sender'], obs_dict['length'], base64.standard_b64decode(obs_dict['payload']), obs_dict['crc']))
    payload_in = base64.standard_b64decode(obs_dict['payload'])
    payload_json = obs_json.payload
    payload_bin = obs_binary.payload
    assert payload_bin == payload_in
    assert payload_json == payload_in
    assert len(obs_dict['obs']) == len(obs_json.obs)
    assert len(obs_dict['obs']) == len(obs_binary.obs)
    obs_json.pack()
    obs_binary.pack()
    assert payload_bin == payload_in
    assert payload_json == payload_in
    assert len(obs_dict['obs']) == len(obs_json.obs)
    assert len(obs_dict['obs']) == len(obs_binary.obs)

    print type(obs_json.header)
    print type(obs_json.header)
    print type(obs_binary.obs)
    print obs_binary.obs
    dir(obs_binary)
    dir(obs_json)
    obs_json.to_binary()
    obs_binary.to_binary()
    assert payload_bin == payload_in
    assert payload_json == payload_in
    assert len(obs_dict['obs']) == len(obs_json.obs)
    assert len(obs_dict['obs']) == len(obs_binary.obs)


if __name__ == "__main__":
    test_roundtrip_payload()
