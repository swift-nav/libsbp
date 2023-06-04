# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Telemetry;

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
package Telemetry::TelemetrySv;

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

    $self->{az} = $self->{_io}->read_u1();
    $self->{el} = $self->{_io}->read_s1();
    $self->{availability_flags} = $self->{_io}->read_u1();
    $self->{pseudorange_residual} = $self->{_io}->read_s2le();
    $self->{phase_residual} = $self->{_io}->read_s2le();
    $self->{outlier_flags} = $self->{_io}->read_u1();
    $self->{ephemeris_flags} = $self->{_io}->read_u1();
    $self->{correction_flags} = $self->{_io}->read_u1();
    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
}

sub az {
    my ($self) = @_;
    return $self->{az};
}

sub el {
    my ($self) = @_;
    return $self->{el};
}

sub availability_flags {
    my ($self) = @_;
    return $self->{availability_flags};
}

sub pseudorange_residual {
    my ($self) = @_;
    return $self->{pseudorange_residual};
}

sub phase_residual {
    my ($self) = @_;
    return $self->{phase_residual};
}

sub outlier_flags {
    my ($self) = @_;
    return $self->{outlier_flags};
}

sub ephemeris_flags {
    my ($self) = @_;
    return $self->{ephemeris_flags};
}

sub correction_flags {
    my ($self) = @_;
    return $self->{correction_flags};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

########################################################################
package Telemetry::MsgTelSv;

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

    $self->{wn} = $self->{_io}->read_u2le();
    $self->{tow} = $self->{_io}->read_u4le();
    $self->{n_obs} = $self->{_io}->read_u1();
    $self->{origin_flags} = $self->{_io}->read_u1();
    $self->{sv_tel} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{sv_tel}}, Telemetry::TelemetrySv->new($self->{_io}, $self, $self->{_root});
    }
}

sub wn {
    my ($self) = @_;
    return $self->{wn};
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub n_obs {
    my ($self) = @_;
    return $self->{n_obs};
}

sub origin_flags {
    my ($self) = @_;
    return $self->{origin_flags};
}

sub sv_tel {
    my ($self) = @_;
    return $self->{sv_tel};
}

1;
