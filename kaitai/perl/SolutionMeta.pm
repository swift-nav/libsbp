# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package SolutionMeta;

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
package SolutionMeta::GnssInputType;

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
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package SolutionMeta::MsgSolnMeta;

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
    $self->{pdop} = $self->{_io}->read_u2le();
    $self->{hdop} = $self->{_io}->read_u2le();
    $self->{vdop} = $self->{_io}->read_u2le();
    $self->{age_corrections} = $self->{_io}->read_u2le();
    $self->{age_gnss} = $self->{_io}->read_u4le();
    $self->{sol_in} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{sol_in}}, SolutionMeta::SolutionInputType->new($self->{_io}, $self, $self->{_root});
    }
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub pdop {
    my ($self) = @_;
    return $self->{pdop};
}

sub hdop {
    my ($self) = @_;
    return $self->{hdop};
}

sub vdop {
    my ($self) = @_;
    return $self->{vdop};
}

sub age_corrections {
    my ($self) = @_;
    return $self->{age_corrections};
}

sub age_gnss {
    my ($self) = @_;
    return $self->{age_gnss};
}

sub sol_in {
    my ($self) = @_;
    return $self->{sol_in};
}

########################################################################
package SolutionMeta::MsgSolnMetaDepA;

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

    $self->{pdop} = $self->{_io}->read_u2le();
    $self->{hdop} = $self->{_io}->read_u2le();
    $self->{vdop} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{age_corrections} = $self->{_io}->read_u2le();
    $self->{alignment_status} = $self->{_io}->read_u1();
    $self->{last_used_gnss_pos_tow} = $self->{_io}->read_u4le();
    $self->{last_used_gnss_vel_tow} = $self->{_io}->read_u4le();
    $self->{sol_in} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{sol_in}}, SolutionMeta::SolutionInputType->new($self->{_io}, $self, $self->{_root});
    }
}

sub pdop {
    my ($self) = @_;
    return $self->{pdop};
}

sub hdop {
    my ($self) = @_;
    return $self->{hdop};
}

sub vdop {
    my ($self) = @_;
    return $self->{vdop};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub age_corrections {
    my ($self) = @_;
    return $self->{age_corrections};
}

sub alignment_status {
    my ($self) = @_;
    return $self->{alignment_status};
}

sub last_used_gnss_pos_tow {
    my ($self) = @_;
    return $self->{last_used_gnss_pos_tow};
}

sub last_used_gnss_vel_tow {
    my ($self) = @_;
    return $self->{last_used_gnss_vel_tow};
}

sub sol_in {
    my ($self) = @_;
    return $self->{sol_in};
}

########################################################################
package SolutionMeta::ImuInputType;

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
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package SolutionMeta::OdoInputType;

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
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package SolutionMeta::SolutionInputType;

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

    $self->{sensor_type} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub sensor_type {
    my ($self) = @_;
    return $self->{sensor_type};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

1;
