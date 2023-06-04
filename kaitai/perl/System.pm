# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;
use Encode;

########################################################################
package System;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

}

########################################################################
package System::MsgHeartbeat;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{flags} = $self->{_io}->read_u4le();
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package System::MsgStatusJournal;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{reporting_system} = $self->{_io}->read_u2le();
    $self->{sbp_version} = $self->{_io}->read_u2le();
    $self->{total_status_reports} = $self->{_io}->read_u4le();
    $self->{sequence_descriptor} = $self->{_io}->read_u1();
    $self->{journal} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{journal}}, System::StatusJournalItem->new($self->{_io}, $self, $self->{_root});
    }
}

sub reporting_system {
    my ($self) = @_;
    return $self->{reporting_system};
}

sub sbp_version {
    my ($self) = @_;
    return $self->{sbp_version};
}

sub total_status_reports {
    my ($self) = @_;
    return $self->{total_status_reports};
}

sub sequence_descriptor {
    my ($self) = @_;
    return $self->{sequence_descriptor};
}

sub journal {
    my ($self) = @_;
    return $self->{journal};
}

########################################################################
package System::MsgInsStatus;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{flags} = $self->{_io}->read_u4le();
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package System::MsgGnssTimeOffset;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{weeks} = $self->{_io}->read_s2le();
    $self->{milliseconds} = $self->{_io}->read_s4le();
    $self->{microseconds} = $self->{_io}->read_s2le();
    $self->{flags} = $self->{_io}->read_u1();
}

sub weeks {
    my ($self) = @_;
    return $self->{weeks};
}

sub milliseconds {
    my ($self) = @_;
    return $self->{milliseconds};
}

sub microseconds {
    my ($self) = @_;
    return $self->{microseconds};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package System::MsgCsacTelemetry;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{id} = $self->{_io}->read_u1();
    $self->{telemetry} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub id {
    my ($self) = @_;
    return $self->{id};
}

sub telemetry {
    my ($self) = @_;
    return $self->{telemetry};
}

########################################################################
package System::MsgPpsTime;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{time} = $self->{_io}->read_u8le();
    $self->{flags} = $self->{_io}->read_u1();
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package System::MsgInsUpdates;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{gnsspos} = $self->{_io}->read_u1();
    $self->{gnssvel} = $self->{_io}->read_u1();
    $self->{wheelticks} = $self->{_io}->read_u1();
    $self->{speed} = $self->{_io}->read_u1();
    $self->{nhc} = $self->{_io}->read_u1();
    $self->{zerovel} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub gnsspos {
    my ($self) = @_;
    return $self->{gnsspos};
}

sub gnssvel {
    my ($self) = @_;
    return $self->{gnssvel};
}

sub wheelticks {
    my ($self) = @_;
    return $self->{wheelticks};
}

sub speed {
    my ($self) = @_;
    return $self->{speed};
}

sub nhc {
    my ($self) = @_;
    return $self->{nhc};
}

sub zerovel {
    my ($self) = @_;
    return $self->{zerovel};
}

########################################################################
package System::MsgDgnssStatus;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{flags} = $self->{_io}->read_u1();
    $self->{latency} = $self->{_io}->read_u2le();
    $self->{num_signals} = $self->{_io}->read_u1();
    $self->{source} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub latency {
    my ($self) = @_;
    return $self->{latency};
}

sub num_signals {
    my ($self) = @_;
    return $self->{num_signals};
}

sub source {
    my ($self) = @_;
    return $self->{source};
}

########################################################################
package System::MsgCsacTelemetryLabels;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{id} = $self->{_io}->read_u1();
    $self->{telemetry_labels} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub id {
    my ($self) = @_;
    return $self->{id};
}

sub telemetry_labels {
    my ($self) = @_;
    return $self->{telemetry_labels};
}

########################################################################
package System::MsgStartup;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{cause} = $self->{_io}->read_u1();
    $self->{startup_type} = $self->{_io}->read_u1();
    $self->{reserved} = $self->{_io}->read_u2le();
}

sub cause {
    my ($self) = @_;
    return $self->{cause};
}

sub startup_type {
    my ($self) = @_;
    return $self->{startup_type};
}

sub reserved {
    my ($self) = @_;
    return $self->{reserved};
}

########################################################################
package System::MsgGroupMeta;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{group_id} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
    $self->{n_group_msgs} = $self->{_io}->read_u1();
    $self->{group_msgs} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{group_msgs}}, $self->{_io}->read_u2le();
    }
}

sub group_id {
    my ($self) = @_;
    return $self->{group_id};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub n_group_msgs {
    my ($self) = @_;
    return $self->{n_group_msgs};
}

sub group_msgs {
    my ($self) = @_;
    return $self->{group_msgs};
}

########################################################################
package System::MsgSensorAidEvent;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{time} = $self->{_io}->read_u4le();
    $self->{sensor_type} = $self->{_io}->read_u1();
    $self->{sensor_id} = $self->{_io}->read_u2le();
    $self->{sensor_state} = $self->{_io}->read_u1();
    $self->{n_available_meas} = $self->{_io}->read_u1();
    $self->{n_attempted_meas} = $self->{_io}->read_u1();
    $self->{n_accepted_meas} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u4le();
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub sensor_type {
    my ($self) = @_;
    return $self->{sensor_type};
}

sub sensor_id {
    my ($self) = @_;
    return $self->{sensor_id};
}

sub sensor_state {
    my ($self) = @_;
    return $self->{sensor_state};
}

sub n_available_meas {
    my ($self) = @_;
    return $self->{n_available_meas};
}

sub n_attempted_meas {
    my ($self) = @_;
    return $self->{n_attempted_meas};
}

sub n_accepted_meas {
    my ($self) = @_;
    return $self->{n_accepted_meas};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package System::SubSystemReport;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{component} = $self->{_io}->read_u2le();
    $self->{generic} = $self->{_io}->read_u1();
    $self->{specific} = $self->{_io}->read_u1();
}

sub component {
    my ($self) = @_;
    return $self->{component};
}

sub generic {
    my ($self) = @_;
    return $self->{generic};
}

sub specific {
    my ($self) = @_;
    return $self->{specific};
}

########################################################################
package System::MsgStatusReport;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{reporting_system} = $self->{_io}->read_u2le();
    $self->{sbp_version} = $self->{_io}->read_u2le();
    $self->{sequence} = $self->{_io}->read_u4le();
    $self->{uptime} = $self->{_io}->read_u4le();
    $self->{status} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{status}}, System::SubSystemReport->new($self->{_io}, $self, $self->{_root});
    }
}

sub reporting_system {
    my ($self) = @_;
    return $self->{reporting_system};
}

sub sbp_version {
    my ($self) = @_;
    return $self->{sbp_version};
}

sub sequence {
    my ($self) = @_;
    return $self->{sequence};
}

sub uptime {
    my ($self) = @_;
    return $self->{uptime};
}

sub status {
    my ($self) = @_;
    return $self->{status};
}

########################################################################
package System::StatusJournalItem;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{uptime} = $self->{_io}->read_u4le();
    $self->{report} = System::SubSystemReport->new($self->{_io}, $self, $self->{_root});
}

sub uptime {
    my ($self) = @_;
    return $self->{uptime};
}

sub report {
    my ($self) = @_;
    return $self->{report};
}

1;
