# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Acquisition;

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
package Acquisition::MsgAcqResultDepC;

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

    $self->{cn0} = $self->{_io}->read_f4le();
    $self->{cp} = $self->{_io}->read_f4le();
    $self->{cf} = $self->{_io}->read_f4le();
    $self->{sid} = Gnss::GnssSignalDep->new($self->{_io}, $self, $self->{_root});
}

sub cn0 {
    my ($self) = @_;
    return $self->{cn0};
}

sub cp {
    my ($self) = @_;
    return $self->{cp};
}

sub cf {
    my ($self) = @_;
    return $self->{cf};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

########################################################################
package Acquisition::MsgAcqResultDepB;

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

    $self->{snr} = $self->{_io}->read_f4le();
    $self->{cp} = $self->{_io}->read_f4le();
    $self->{cf} = $self->{_io}->read_f4le();
    $self->{sid} = Gnss::GnssSignalDep->new($self->{_io}, $self, $self->{_root});
}

sub snr {
    my ($self) = @_;
    return $self->{snr};
}

sub cp {
    my ($self) = @_;
    return $self->{cp};
}

sub cf {
    my ($self) = @_;
    return $self->{cf};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

########################################################################
package Acquisition::AcqSvProfile;

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

    $self->{job_type} = $self->{_io}->read_u1();
    $self->{status} = $self->{_io}->read_u1();
    $self->{cn0} = $self->{_io}->read_u2le();
    $self->{int_time} = $self->{_io}->read_u1();
    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{bin_width} = $self->{_io}->read_u2le();
    $self->{timestamp} = $self->{_io}->read_u4le();
    $self->{time_spent} = $self->{_io}->read_u4le();
    $self->{cf_min} = $self->{_io}->read_s4le();
    $self->{cf_max} = $self->{_io}->read_s4le();
    $self->{cf} = $self->{_io}->read_s4le();
    $self->{cp} = $self->{_io}->read_u4le();
}

sub job_type {
    my ($self) = @_;
    return $self->{job_type};
}

sub status {
    my ($self) = @_;
    return $self->{status};
}

sub cn0 {
    my ($self) = @_;
    return $self->{cn0};
}

sub int_time {
    my ($self) = @_;
    return $self->{int_time};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub bin_width {
    my ($self) = @_;
    return $self->{bin_width};
}

sub timestamp {
    my ($self) = @_;
    return $self->{timestamp};
}

sub time_spent {
    my ($self) = @_;
    return $self->{time_spent};
}

sub cf_min {
    my ($self) = @_;
    return $self->{cf_min};
}

sub cf_max {
    my ($self) = @_;
    return $self->{cf_max};
}

sub cf {
    my ($self) = @_;
    return $self->{cf};
}

sub cp {
    my ($self) = @_;
    return $self->{cp};
}

########################################################################
package Acquisition::MsgAcqSvProfile;

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

    $self->{acq_sv_profile} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{acq_sv_profile}}, Acquisition::AcqSvProfile->new($self->{_io}, $self, $self->{_root});
    }
}

sub acq_sv_profile {
    my ($self) = @_;
    return $self->{acq_sv_profile};
}

########################################################################
package Acquisition::AcqSvProfileDep;

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

    $self->{job_type} = $self->{_io}->read_u1();
    $self->{status} = $self->{_io}->read_u1();
    $self->{cn0} = $self->{_io}->read_u2le();
    $self->{int_time} = $self->{_io}->read_u1();
    $self->{sid} = Gnss::GnssSignalDep->new($self->{_io}, $self, $self->{_root});
    $self->{bin_width} = $self->{_io}->read_u2le();
    $self->{timestamp} = $self->{_io}->read_u4le();
    $self->{time_spent} = $self->{_io}->read_u4le();
    $self->{cf_min} = $self->{_io}->read_s4le();
    $self->{cf_max} = $self->{_io}->read_s4le();
    $self->{cf} = $self->{_io}->read_s4le();
    $self->{cp} = $self->{_io}->read_u4le();
}

sub job_type {
    my ($self) = @_;
    return $self->{job_type};
}

sub status {
    my ($self) = @_;
    return $self->{status};
}

sub cn0 {
    my ($self) = @_;
    return $self->{cn0};
}

sub int_time {
    my ($self) = @_;
    return $self->{int_time};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub bin_width {
    my ($self) = @_;
    return $self->{bin_width};
}

sub timestamp {
    my ($self) = @_;
    return $self->{timestamp};
}

sub time_spent {
    my ($self) = @_;
    return $self->{time_spent};
}

sub cf_min {
    my ($self) = @_;
    return $self->{cf_min};
}

sub cf_max {
    my ($self) = @_;
    return $self->{cf_max};
}

sub cf {
    my ($self) = @_;
    return $self->{cf};
}

sub cp {
    my ($self) = @_;
    return $self->{cp};
}

########################################################################
package Acquisition::MsgAcqResult;

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

    $self->{cn0} = $self->{_io}->read_f4le();
    $self->{cp} = $self->{_io}->read_f4le();
    $self->{cf} = $self->{_io}->read_f4le();
    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
}

sub cn0 {
    my ($self) = @_;
    return $self->{cn0};
}

sub cp {
    my ($self) = @_;
    return $self->{cp};
}

sub cf {
    my ($self) = @_;
    return $self->{cf};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

########################################################################
package Acquisition::MsgAcqResultDepA;

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

    $self->{snr} = $self->{_io}->read_f4le();
    $self->{cp} = $self->{_io}->read_f4le();
    $self->{cf} = $self->{_io}->read_f4le();
    $self->{prn} = $self->{_io}->read_u1();
}

sub snr {
    my ($self) = @_;
    return $self->{snr};
}

sub cp {
    my ($self) = @_;
    return $self->{cp};
}

sub cf {
    my ($self) = @_;
    return $self->{cf};
}

sub prn {
    my ($self) = @_;
    return $self->{prn};
}

########################################################################
package Acquisition::MsgAcqSvProfileDep;

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

    $self->{acq_sv_profile} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{acq_sv_profile}}, Acquisition::AcqSvProfileDep->new($self->{_io}, $self, $self->{_root});
    }
}

sub acq_sv_profile {
    my ($self) = @_;
    return $self->{acq_sv_profile};
}

1;
