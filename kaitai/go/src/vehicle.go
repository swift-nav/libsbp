// Code generated by kaitai-struct-compiler from a .ksy source file. DO NOT EDIT.

import "github.com/kaitai-io/kaitai_struct_go_runtime/kaitai"

type Vehicle struct {
	_io *kaitai.Stream
	_root *Vehicle
	_parent interface{}
}
func NewVehicle() *Vehicle {
	return &Vehicle{
	}
}

func (this *Vehicle) Read(io *kaitai.Stream, parent interface{}, root *Vehicle) (err error) {
	this._io = io
	this._parent = parent
	this._root = root

	return err
}

/**
 * Message representing the x component of vehicle velocity in the user
 * frame at the odometry reference point(s) specified by the user. The
 * offset for the odometry reference point and the definition and origin of
 * the user frame are defined through the device settings interface. There
 * are 4 possible user-defined sources of this message which are labeled
 * arbitrarily source 0 through 3. If using "processor time" time tags, the
 * receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
 * becomes available to synchronise odometry measurements with GNSS.
 * Processor time shall roll over to zero after one week.
 */
type Vehicle_MsgOdometry struct {
	Tow uint32
	Velocity int32
	Flags uint8
	_io *kaitai.Stream
	_root *Vehicle
	_parent *Sbp_Message
}
func NewVehicle_MsgOdometry() *Vehicle_MsgOdometry {
	return &Vehicle_MsgOdometry{
	}
}

func (this *Vehicle_MsgOdometry) Read(io *kaitai.Stream, parent *Sbp_Message, root *Vehicle) (err error) {
	this._io = io
	this._parent = parent
	this._root = root

	tmp1, err := this._io.ReadU4le()
	if err != nil {
		return err
	}
	this.Tow = uint32(tmp1)
	tmp2, err := this._io.ReadS4le()
	if err != nil {
		return err
	}
	this.Velocity = int32(tmp2)
	tmp3, err := this._io.ReadU1()
	if err != nil {
		return err
	}
	this.Flags = tmp3
	return err
}

/**
 * Time field representing either milliseconds in the GPS Week or local
 * CPU time from the producing system in milliseconds.  See the
 * tow_source flag for the exact source of this timestamp.
 */

/**
 * The signed forward component of vehicle velocity.
 */

/**
 * Status flags
 */

/**
 * Message containing the accumulated distance travelled by a wheel located
 * at an odometry reference point defined by the user. The offset for the
 * odometry reference point and the definition and origin of the user frame
 * are defined through the device settings interface. The source of this
 * message is identified by the source field, which is an integer ranging
 * from 0 to 255. The timestamp associated with this message should
 * represent the time when the accumulated tick count reached the value
 * given by the contents of this message as accurately as possible. If
 * using "local CPU time" time tags, the receiving end will expect a
 * `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise
 * wheeltick measurements with GNSS. Local CPU time shall roll over to zero
 * after one week.
 */
type Vehicle_MsgWheeltick struct {
	Time uint64
	Flags uint8
	Source uint8
	Ticks int32
	_io *kaitai.Stream
	_root *Vehicle
	_parent *Sbp_Message
}
func NewVehicle_MsgWheeltick() *Vehicle_MsgWheeltick {
	return &Vehicle_MsgWheeltick{
	}
}

func (this *Vehicle_MsgWheeltick) Read(io *kaitai.Stream, parent *Sbp_Message, root *Vehicle) (err error) {
	this._io = io
	this._parent = parent
	this._root = root

	tmp4, err := this._io.ReadU8le()
	if err != nil {
		return err
	}
	this.Time = uint64(tmp4)
	tmp5, err := this._io.ReadU1()
	if err != nil {
		return err
	}
	this.Flags = tmp5
	tmp6, err := this._io.ReadU1()
	if err != nil {
		return err
	}
	this.Source = tmp6
	tmp7, err := this._io.ReadS4le()
	if err != nil {
		return err
	}
	this.Ticks = int32(tmp7)
	return err
}

/**
 * Time field representing either microseconds since the last PPS,
 * microseconds in the GPS Week or local CPU time from the producing
 * system in microseconds. See the synch_type field for the exact
 * meaning of this timestamp.
 */

/**
 * Field indicating the type of timestamp contained in the time field.
 */

/**
 * ID of the sensor producing this message
 */

/**
 * Free-running counter of the accumulated distance for this sensor.
 * The counter should be incrementing if travelling into one direction
 * and decrementing when travelling in the opposite direction.
 */