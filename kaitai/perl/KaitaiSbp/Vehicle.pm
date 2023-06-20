# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Vehicle;

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
package Vehicle::MsgOdometry;

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
    $self->{velocity} = $self->{_io}->read_s4le();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub velocity {
    my ($self) = @_;
    return $self->{velocity};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Vehicle::MsgWheeltick;

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
    $self->{source} = $self->{_io}->read_u1();
    $self->{ticks} = $self->{_io}->read_s4le();
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub source {
    my ($self) = @_;
    return $self->{source};
}

sub ticks {
    my ($self) = @_;
    return $self->{ticks};
}

1;
