# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
use KaitaiSbp::Gnss;

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Tracking;

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
package Tracking::MsgTrackingStateDetailedDep;

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

    $self->{recv_time} = $self->{_io}->read_u8le();
    $self->{tot} = Gnss::GpsTimeDep->new($self->{_io}, $self, $self->{_root});
    $self->{p} = $self->{_io}->read_u4le();
    $self->{p_std} = $self->{_io}->read_u2le();
    $self->{l} = Gnss::CarrierPhase->new($self->{_io}, $self, $self->{_root});
    $self->{cn0} = $self->{_io}->read_u1();
    $self->{lock} = $self->{_io}->read_u2le();
    $self->{sid} = Gnss::GnssSignalDep->new($self->{_io}, $self, $self->{_root});
    $self->{doppler} = $self->{_io}->read_s4le();
    $self->{doppler_std} = $self->{_io}->read_u2le();
    $self->{uptime} = $self->{_io}->read_u4le();
    $self->{clock_offset} = $self->{_io}->read_s2le();
    $self->{clock_drift} = $self->{_io}->read_s2le();
    $self->{corr_spacing} = $self->{_io}->read_u2le();
    $self->{acceleration} = $self->{_io}->read_s1();
    $self->{sync_flags} = $self->{_io}->read_u1();
    $self->{tow_flags} = $self->{_io}->read_u1();
    $self->{track_flags} = $self->{_io}->read_u1();
    $self->{nav_flags} = $self->{_io}->read_u1();
    $self->{pset_flags} = $self->{_io}->read_u1();
    $self->{misc_flags} = $self->{_io}->read_u1();
}

sub recv_time {
    my ($self) = @_;
    return $self->{recv_time};
}

sub tot {
    my ($self) = @_;
    return $self->{tot};
}

sub p {
    my ($self) = @_;
    return $self->{p};
}

sub p_std {
    my ($self) = @_;
    return $self->{p_std};
}

sub l {
    my ($self) = @_;
    return $self->{l};
}

sub cn0 {
    my ($self) = @_;
    return $self->{cn0};
}

sub lock {
    my ($self) = @_;
    return $self->{lock};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub doppler {
    my ($self) = @_;
    return $self->{doppler};
}

sub doppler_std {
    my ($self) = @_;
    return $self->{doppler_std};
}

sub uptime {
    my ($self) = @_;
    return $self->{uptime};
}

sub clock_offset {
    my ($self) = @_;
    return $self->{clock_offset};
}

sub clock_drift {
    my ($self) = @_;
    return $self->{clock_drift};
}

sub corr_spacing {
    my ($self) = @_;
    return $self->{corr_spacing};
}

sub acceleration {
    my ($self) = @_;
    return $self->{acceleration};
}

sub sync_flags {
    my ($self) = @_;
    return $self->{sync_flags};
}

sub tow_flags {
    my ($self) = @_;
    return $self->{tow_flags};
}

sub track_flags {
    my ($self) = @_;
    return $self->{track_flags};
}

sub nav_flags {
    my ($self) = @_;
    return $self->{nav_flags};
}

sub pset_flags {
    my ($self) = @_;
    return $self->{pset_flags};
}

sub misc_flags {
    my ($self) = @_;
    return $self->{misc_flags};
}

########################################################################
package Tracking::TrackingChannelStateDepB;

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

    $self->{state} = $self->{_io}->read_u1();
    $self->{sid} = Gnss::GnssSignalDep->new($self->{_io}, $self, $self->{_root});
    $self->{cn0} = $self->{_io}->read_f4le();
}

sub state {
    my ($self) = @_;
    return $self->{state};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub cn0 {
    my ($self) = @_;
    return $self->{cn0};
}

########################################################################
package Tracking::TrackingChannelState;

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

    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{fcn} = $self->{_io}->read_u1();
    $self->{cn0} = $self->{_io}->read_u1();
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub fcn {
    my ($self) = @_;
    return $self->{fcn};
}

sub cn0 {
    my ($self) = @_;
    return $self->{cn0};
}

########################################################################
package Tracking::MsgTrackingState;

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

    $self->{states} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{states}}, Tracking::TrackingChannelState->new($self->{_io}, $self, $self->{_root});
    }
}

sub states {
    my ($self) = @_;
    return $self->{states};
}

########################################################################
package Tracking::TrackingChannelStateDepA;

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

    $self->{state} = $self->{_io}->read_u1();
    $self->{prn} = $self->{_io}->read_u1();
    $self->{cn0} = $self->{_io}->read_f4le();
}

sub state {
    my ($self) = @_;
    return $self->{state};
}

sub prn {
    my ($self) = @_;
    return $self->{prn};
}

sub cn0 {
    my ($self) = @_;
    return $self->{cn0};
}

########################################################################
package Tracking::MsgTrackingIqDepA;

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

    $self->{channel} = $self->{_io}->read_u1();
    $self->{sid} = Gnss::GnssSignalDep->new($self->{_io}, $self, $self->{_root});
    $self->{corrs} = [];
    my $n_corrs = 3;
    for (my $i = 0; $i < $n_corrs; $i++) {
        push @{$self->{corrs}}, $self->{_io}->read_u8le();
    }
}

sub channel {
    my ($self) = @_;
    return $self->{channel};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub corrs {
    my ($self) = @_;
    return $self->{corrs};
}

########################################################################
package Tracking::TrackingChannelCorrelationDep;

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

    $self->{i} = $self->{_io}->read_s4le();
    $self->{q} = $self->{_io}->read_s4le();
}

sub i {
    my ($self) = @_;
    return $self->{i};
}

sub q {
    my ($self) = @_;
    return $self->{q};
}

########################################################################
package Tracking::MsgTrackingStateDepA;

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

    $self->{states} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{states}}, Tracking::TrackingChannelStateDepA->new($self->{_io}, $self, $self->{_root});
    }
}

sub states {
    my ($self) = @_;
    return $self->{states};
}

########################################################################
package Tracking::MsgMeasurementState;

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

    $self->{states} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{states}}, Tracking::MeasurementState->new($self->{_io}, $self, $self->{_root});
    }
}

sub states {
    my ($self) = @_;
    return $self->{states};
}

########################################################################
package Tracking::TrackingChannelCorrelation;

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

    $self->{i} = $self->{_io}->read_s2le();
    $self->{q} = $self->{_io}->read_s2le();
}

sub i {
    my ($self) = @_;
    return $self->{i};
}

sub q {
    my ($self) = @_;
    return $self->{q};
}

########################################################################
package Tracking::MsgTrackingIq;

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

    $self->{channel} = $self->{_io}->read_u1();
    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{corrs} = [];
    my $n_corrs = 3;
    for (my $i = 0; $i < $n_corrs; $i++) {
        push @{$self->{corrs}}, $self->{_io}->read_u8le();
    }
}

sub channel {
    my ($self) = @_;
    return $self->{channel};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub corrs {
    my ($self) = @_;
    return $self->{corrs};
}

########################################################################
package Tracking::MsgTrackingStateDetailedDepA;

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

    $self->{recv_time} = $self->{_io}->read_u8le();
    $self->{tot} = Gnss::GpsTime->new($self->{_io}, $self, $self->{_root});
    $self->{p} = $self->{_io}->read_u4le();
    $self->{p_std} = $self->{_io}->read_u2le();
    $self->{l} = Gnss::CarrierPhase->new($self->{_io}, $self, $self->{_root});
    $self->{cn0} = $self->{_io}->read_u1();
    $self->{lock} = $self->{_io}->read_u2le();
    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{doppler} = $self->{_io}->read_s4le();
    $self->{doppler_std} = $self->{_io}->read_u2le();
    $self->{uptime} = $self->{_io}->read_u4le();
    $self->{clock_offset} = $self->{_io}->read_s2le();
    $self->{clock_drift} = $self->{_io}->read_s2le();
    $self->{corr_spacing} = $self->{_io}->read_u2le();
    $self->{acceleration} = $self->{_io}->read_s1();
    $self->{sync_flags} = $self->{_io}->read_u1();
    $self->{tow_flags} = $self->{_io}->read_u1();
    $self->{track_flags} = $self->{_io}->read_u1();
    $self->{nav_flags} = $self->{_io}->read_u1();
    $self->{pset_flags} = $self->{_io}->read_u1();
    $self->{misc_flags} = $self->{_io}->read_u1();
}

sub recv_time {
    my ($self) = @_;
    return $self->{recv_time};
}

sub tot {
    my ($self) = @_;
    return $self->{tot};
}

sub p {
    my ($self) = @_;
    return $self->{p};
}

sub p_std {
    my ($self) = @_;
    return $self->{p_std};
}

sub l {
    my ($self) = @_;
    return $self->{l};
}

sub cn0 {
    my ($self) = @_;
    return $self->{cn0};
}

sub lock {
    my ($self) = @_;
    return $self->{lock};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub doppler {
    my ($self) = @_;
    return $self->{doppler};
}

sub doppler_std {
    my ($self) = @_;
    return $self->{doppler_std};
}

sub uptime {
    my ($self) = @_;
    return $self->{uptime};
}

sub clock_offset {
    my ($self) = @_;
    return $self->{clock_offset};
}

sub clock_drift {
    my ($self) = @_;
    return $self->{clock_drift};
}

sub corr_spacing {
    my ($self) = @_;
    return $self->{corr_spacing};
}

sub acceleration {
    my ($self) = @_;
    return $self->{acceleration};
}

sub sync_flags {
    my ($self) = @_;
    return $self->{sync_flags};
}

sub tow_flags {
    my ($self) = @_;
    return $self->{tow_flags};
}

sub track_flags {
    my ($self) = @_;
    return $self->{track_flags};
}

sub nav_flags {
    my ($self) = @_;
    return $self->{nav_flags};
}

sub pset_flags {
    my ($self) = @_;
    return $self->{pset_flags};
}

sub misc_flags {
    my ($self) = @_;
    return $self->{misc_flags};
}

########################################################################
package Tracking::MsgTrackingStateDepB;

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

    $self->{states} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{states}}, Tracking::TrackingChannelStateDepB->new($self->{_io}, $self, $self->{_root});
    }
}

sub states {
    my ($self) = @_;
    return $self->{states};
}

########################################################################
package Tracking::MeasurementState;

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

    $self->{mesid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{cn0} = $self->{_io}->read_u1();
}

sub mesid {
    my ($self) = @_;
    return $self->{mesid};
}

sub cn0 {
    my ($self) = @_;
    return $self->{cn0};
}

########################################################################
package Tracking::MsgTrackingIqDepB;

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

    $self->{channel} = $self->{_io}->read_u1();
    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{corrs} = [];
    my $n_corrs = 3;
    for (my $i = 0; $i < $n_corrs; $i++) {
        push @{$self->{corrs}}, $self->{_io}->read_u8le();
    }
}

sub channel {
    my ($self) = @_;
    return $self->{channel};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub corrs {
    my ($self) = @_;
    return $self->{corrs};
}

1;
