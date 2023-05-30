# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Flash;

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
package Flash::MsgFlashDone;

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

    $self->{response} = $self->{_io}->read_u1();
}

sub response {
    my ($self) = @_;
    return $self->{response};
}

########################################################################
package Flash::MsgM25FlashWriteStatus;

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

    $self->{status} = ();
    my $n_status = 1;
    for (my $i = 0; $i < $n_status; $i++) {
        push @{$self->{status}}, $self->{_io}->read_u1();
    }
}

sub status {
    my ($self) = @_;
    return $self->{status};
}

########################################################################
package Flash::MsgFlashReadResp;

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

    $self->{target} = $self->{_io}->read_u1();
    $self->{addr_start} = ();
    my $n_addr_start = 3;
    for (my $i = 0; $i < $n_addr_start; $i++) {
        push @{$self->{addr_start}}, $self->{_io}->read_u1();
    }
    $self->{addr_len} = $self->{_io}->read_u1();
}

sub target {
    my ($self) = @_;
    return $self->{target};
}

sub addr_start {
    my ($self) = @_;
    return $self->{addr_start};
}

sub addr_len {
    my ($self) = @_;
    return $self->{addr_len};
}

########################################################################
package Flash::MsgFlashErase;

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

    $self->{target} = $self->{_io}->read_u1();
    $self->{sector_num} = $self->{_io}->read_u4le();
}

sub target {
    my ($self) = @_;
    return $self->{target};
}

sub sector_num {
    my ($self) = @_;
    return $self->{sector_num};
}

########################################################################
package Flash::MsgStmUniqueIdResp;

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

    $self->{stm_id} = ();
    my $n_stm_id = 12;
    for (my $i = 0; $i < $n_stm_id; $i++) {
        push @{$self->{stm_id}}, $self->{_io}->read_u1();
    }
}

sub stm_id {
    my ($self) = @_;
    return $self->{stm_id};
}

########################################################################
package Flash::MsgStmUniqueIdReq;

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
package Flash::MsgFlashProgram;

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

    $self->{target} = $self->{_io}->read_u1();
    $self->{addr_start} = ();
    my $n_addr_start = 3;
    for (my $i = 0; $i < $n_addr_start; $i++) {
        push @{$self->{addr_start}}, $self->{_io}->read_u1();
    }
    $self->{addr_len} = $self->{_io}->read_u1();
    $self->{data} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{data}}, $self->{_io}->read_u1();
    }
}

sub target {
    my ($self) = @_;
    return $self->{target};
}

sub addr_start {
    my ($self) = @_;
    return $self->{addr_start};
}

sub addr_len {
    my ($self) = @_;
    return $self->{addr_len};
}

sub data {
    my ($self) = @_;
    return $self->{data};
}

########################################################################
package Flash::MsgFlashReadReq;

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

    $self->{target} = $self->{_io}->read_u1();
    $self->{addr_start} = ();
    my $n_addr_start = 3;
    for (my $i = 0; $i < $n_addr_start; $i++) {
        push @{$self->{addr_start}}, $self->{_io}->read_u1();
    }
    $self->{addr_len} = $self->{_io}->read_u1();
}

sub target {
    my ($self) = @_;
    return $self->{target};
}

sub addr_start {
    my ($self) = @_;
    return $self->{addr_start};
}

sub addr_len {
    my ($self) = @_;
    return $self->{addr_len};
}

########################################################################
package Flash::MsgStmFlashUnlockSector;

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

    $self->{sector} = $self->{_io}->read_u4le();
}

sub sector {
    my ($self) = @_;
    return $self->{sector};
}

########################################################################
package Flash::MsgStmFlashLockSector;

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

    $self->{sector} = $self->{_io}->read_u4le();
}

sub sector {
    my ($self) = @_;
    return $self->{sector};
}

1;
